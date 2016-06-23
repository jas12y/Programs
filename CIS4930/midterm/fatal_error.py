""" John Stubbs jas12y
    pylint 1.1.0
    This module is a game and stuff """

from __future__ import print_function
from random import randint
import socket
import threading

ROWS = 5
COLUMNS = 5

class Character(object):
    """ Character """
    board = [[False for each in range(COLUMNS)]for each in range(ROWS)]
    def __init__(self, name, connection):
        """ Initalize Character """
        self.con = connection
        self.name = name
        self.row, self.column = self.get_position()
        self.hit_points = 0
        self.health_max = 0
        self.strength = 0
        self.defence = 0


    def get_position(self):
        """ Random position """
        random_row = randint(0, ROWS - 1)
        random_column = randint(0, COLUMNS - 1)
        while Character.board[random_row][random_column] or (random_row == 2 and random_column == 0):
            random_row = randint(0, ROWS - 1)
            random_column = randint(0, COLUMNS - 1)
        Character.board[random_row][random_column] = self.name
        return random_row, random_column

    def get_damage(self, opponent):
        """ Damage """
        damage = randint(0, 6) + self.strength - opponent.defence
        if damage <= 0:
            self.con.send("%s evades %s's attack.\n" %
                          (opponent.name, self.name))
        else:
            opponent.hit_points = opponent.hit_points - damage
            self.con.send("%s attacks %s for %s points of damage!\n" %
                          (self.name, opponent.name, str(damage)))

class EvilRobot(Character):
    """ Evil Robot """
    def __init__(self, connection):
        """ Initalize Evil Robot """
        Character.__init__(self, "Evil Robot", connection)
        self.hit_points = 15
        self.health_max = 15
        self.strength = 9
        self.defence = 7

class Player(Character):
    """ Player """
    def __init__(self, name, connection):
        """ Initalize Player """
        Character.__init__(self, name, connection)
        self.row = 2
        self.column = 0
        self.hit_points = 30
        self.health_max = 30
        self.state = "search"

    def help(self):
        """ Help """
        self.con.send("Commands:\n")
        self.con.send("go [N, S, E, or W]\n")
        self.con.send("quit\n")
        self.con.send("attack\n")
        self.con.send("health\n")
        self.con.send("help\n")

    def quit(self):
        """ Quit """
        self.con.send("You give up and die!\n")
        self.hit_points = 0

    def health(self):
        """ Health """
        self.con.send("%s has %sHP\n" % (self.name, str(self.hit_points)))

    def attack(self, enemy):
        """ Attack """
        self.get_damage(enemy)
        if self.hit_points <= 0:
            self.con.send("%s has been killed by the Evil Robot\n" % self.name)
        if enemy.hit_points <= 0:
            self.board[enemy.row][enemy.column] = False
            self.state = "search"
            self.con.send("%s killed the Evil Robot\n" % self.name)

    def move(self, direction):
        """ Move """
        if self.state != "fight":
            if direction.upper() == 'N':
                if self.row == 0:
                    self.con.send("%s ran into a wall.\n" % self.name)
                else:
                    self.row -= 1
            elif direction.upper() == 'S':
                if self.row == (ROWS - 1):
                    self.con.send("%s ran into a wall.\n" % self.name)
                else:
                    self.row += 1
            elif direction.upper() == 'E':
                if self.column == (COLUMNS - 1):
                    self.con.send("%s ran into a wall.\n" % self.name)
                else:
                    self.column += 1
            elif direction.upper() == 'W':
                if self.column == 0:
                    self.con.send("%s ran into a wall.\n" % self.name)
                else:
                    self.column -= 1
            else:
                self.con.send("Please enter \"go [N, S, E, or W]\"\n")
            if self.board[self.row][self.column] == "Evil Robot":
                self.state = "fight"
                self.con.send("It's a freaking Evil Robot!\n")
            elif self.board[self.row][self.column] == "Rat Trap":
                self.game_over(False)
            elif self.board[self.row][self.column] == "Backpack":
                self.game_over(True)
        else:
            self.con.send("You must fight to survive!\n")

    def game_over(self, win):
        """ End Game """
        if win:
            self.con.send("You found your backpack!\n")
        else:
            self.con.send("You stepped in a trap!\n")
        self.hit_points = 0

class CodeWarrior(Player):
    """ CodeWarrior """
    def __init__(self, name, connection):
        Player.__init__(self, name, connection)
        self.strength = 10
        self.defence = 8

class H4x0r(Player):
    """ H4x0r """
    def __init__(self, name, connection):
        Player.__init__(self, name, connection)
        self.strength = 8
        self.defence = 10

def fatal_error(connection):
    """ Fatal Error """
    con = connection
    robots = []
    Character("Backpack", con)
    Character("Rat Trap", con)
    for each in range(4):
        robots.append(EvilRobot(con))
    con.send("Enter your character's name: ")
    player_name = con.recv(64).rstrip()
    con.send("Are you a CodeWarrior or 1337H4x0r? Enter [c] or [h]: ")
    player_type = con.recv(4)
    while player_type[0].lower() != "c" and player_type[0].lower() != "h":
        con.send("Please enter [c] or [h]: ")
        player_type = con.recv(4)
    if player_type.lower() == "c":
        player = CodeWarrior(player_name, con)
    else:
        player = H4x0r(player_name, con)

    player.help()
    while player.hit_points > 0:
        con.send("> ")
        command = con.recv(24).rstrip()
        args = command.split()
        if args[0] == "help":
            player.help()
        elif args[0] == "quit":
            player.quit()
        elif args[0] == "attack":
            if player.state == "fight":
                for enemy in robots:
                    if enemy.row == player.row and enemy.column == player.column:
                        player.attack(enemy)
                        if enemy.hit_points > 0:
                            enemy.get_damage(player)
            else:
                con.send("Swing and a miss\n")
        elif args[0] == "health":
            player.health()
        elif args[0] == "go":
            player.move(args[1])
            if player.state == "fight":
                if randint(0, 1):
                    robots[0].get_damage(player)
        else:
            con.send("Invalid command\n")

    con.close()

if __name__ == "__main__":
    MYSOCKET = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    MYSOCKET.bind(("", 9000))
    MYSOCKET.listen(5)
    while True:
        CONNECTION, ADDRESS = MYSOCKET.accept()
        MYTHREAD = threading.Thread(target=fatal_error, args=(CONNECTION,))
        MYTHREAD.start()
