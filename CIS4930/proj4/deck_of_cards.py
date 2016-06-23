""" John Stubbs jas12y
    pylint 1.1.0
    This module defines three classes:
    Card, Hand, and Deck """

from __future__ import print_function
import random

class Card(object):
    """ CLass that defines Card
        (single card) """

    snames = ["Clubs", "Diamonds", "Hearts", "Spades"]
    rnames = [None, "Ace", "2", "3", "4", "5", "6", "7"
             , "8", "9", "10", "Jack", "Queen", "King"]

    def __init__(self, suit, rank):
        """ Initialize suit and rank """
        self.suit = suit
        self.rank = rank

    def __str__(self):
        """ Returns suit and rank """
        return Card.rnames[self.rank] + " of " + Card.snames[self.suit]

    def value(self):
        """ Returns value """
        if self.rank < 10:
            return self.rank
        return 10

class Deck(object):
    """ Class that defines Deck
        (52 card) """

    def __init__(self):
        """ Initializes sorted deck """
        self.cards = []
        for suit in range(4):
            for rank in range(1, 14):
                card = Card(suit, rank)
                self.cards.append(card)

    def add_card(self, card):
        """ Adds card to deck """
        self.cards.append(card)

    def remove_card(self, card):
        """ Removes card from deck """
        self.cards.remove(card)

    def pop_card(self, index=-1):
        """ Removes and returns the last card """
        return self.cards.pop(index)

    def shuffle(self):
        """ Shuffles the deck """
        random.shuffle(self.cards)

    def sort(self):
        """ Puts the cards in order """
        self.cards.sort()

    def move_cards(self, hand, number):
        """ Moves a number of cards
            into the hand """
        count = 0
        while count < number:
            hand.add_card(self.cards.pop())
            count += 1

class Hand(Deck):
    """ Class that defines Hand
        (collection of cards) """

    def __init__(self):
        """ Creates an empty hand """
        self.cards = []

    def __str__(self):
        """ Show cards in hand """
        rtn = []
        for card in self.cards:
            rtn.append(str(card))
        return " ".join(rtn)

    def size(self):
        """ Returns size of hand """
        return len(self.cards)
