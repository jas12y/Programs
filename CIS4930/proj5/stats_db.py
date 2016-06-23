""" John Stubbs jas12y
    pylint 1.1.0
    This module inserts values
    to database and returns top
    players """

import sqlite3

def top_percent():
    """ Returns top three highest winners """
    conn = sqlite3.connect("statistics.db")
    conn_cursor = conn.cursor()
    conn_cursor.execute("SELECT * FROM Statistics ORDER BY percent DESC;")
    result_rows = conn_cursor.fetchmany(5)
    conn.close()
    return result_rows

def insert_stat(name, wins, plays):
    """ Inserts a name and score """
    conn = sqlite3.connect("statistics.db")
    percent = wins / float(plays)
    conn_cursor = conn.cursor()
    conn_cursor.execute("INSERT INTO Statistics VALUES (?, ?, ?, ?);",
        (name, wins, plays, percent))
    conn.commit()
    conn.close()
