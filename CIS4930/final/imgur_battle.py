""" John Stubbs jas12y
    pylint 1.1.0
    This module finds the winner
    between n number imgur users """

import requests
import json

def battle(*names):
    """ Compare player points on imgur """
    players = {}
    posts = []
    for name in names:
        print "Username: {0}".format(name)
        players[name] = get_info(name)
        posts.append(players[name].keys())
    same = set(posts[0]).intersection(*posts)
    print "All users have commented on these posts: {0}".format(" ".join(str(e) for e in same))
    winner = ""
    max_points = 0
    if len(same) > 0:
        for each in players:
            total = 0
            for point in same:
                total += players[each][point]
            print "User {0} has a total of {1} points.".format(each, total)
            if total > max_points:
                max_points = total
                winner = each
        print "The winner is {0}!".format(winner)
    else:
        print "The users haven't commented on the same post"

def get_info(name):
    """ Gets info from imgur """
    num = 0
    user = {}
    url = "http://imgur.com/user/{0}/index/newest/page/{1}/hit.json?scrolling".format(name, num)
    page = requests.get(url)
    while not page.text == "":
        data = json.loads(page.text)
        temp = data["data"]["captions"]["data"]
        for entry in temp:
            if user.get(entry["hash"]) == None:
                user[entry["hash"]] = entry["points"]
            else:
                user[entry["hash"]] += entry["points"]
        num += 1
        url = "http://imgur.com/user/{0}/index/newest/page/{1}/hit.json?scrolling".format(name, num)
        page = requests.get(url)
    return user
