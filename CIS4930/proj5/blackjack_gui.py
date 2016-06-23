""" John Stubbs jas12y
    pylint 1.1.0
    Modified blackjack for
    assignment 5 """

import sys
from PyQt4 import QtGui, QtCore, Qt
from card_table import *
from stats_db import *

class BlackjackApp(QtGui.QMainWindow):
    
    def __init__(self):
        super(BlackjackApp, self).__init__()
        self.initUI()        
        
    def initUI(self):
        QtGui.QToolTip.setFont(QtGui.QFont('SansSerif', 10))
        self.setToolTip('Play Gooey Blackjack!')

        exitAction = QtGui.QAction('Exit', self)        
        exitAction.setShortcut('Ctrl+Q')
        exitAction.setStatusTip('Exit application')
        exitAction.triggered.connect(app.quit)

        statAction = QtGui.QAction('Stats', self)
        statAction.setStatusTip('Stats')
        statAction.triggered.connect(self.showStats)

        menubar = self.menuBar()
        fileMenu = menubar.addMenu('File')
        fileMenu.addAction(exitAction)
        gameMenu = menubar.addMenu('Game')
        gameMenu.addAction(statAction)

        statbar = self.statusBar()

        self.c = CardTable()
        self.setCentralWidget(self.c)

        self.setGeometry(300, 300, 600, 400)
        self.setWindowTitle('Gooey Blackjack')
        self.show()

    def showStats(self):
        top_scores = "Name\twins\tplays\tpercent\n"
        rows = top_percent()
        for row in rows:
            top_scores += "\n{0}\t{1}\t{2}\t{3:.2f}".format(row[0], row[1], row[2], row[3])
        QtGui.QMessageBox.about(self, 'Stats', top_scores)

    def closeEvent(self, event):
        reply = QtGui.QMessageBox.question(self, 'Message',
            "Are you sure?", QtGui.QMessageBox.Yes | 
            QtGui.QMessageBox.No, QtGui.QMessageBox.No)
        if reply == QtGui.QMessageBox.Yes:
            if(self.c.gamesPlayed > 0):
                insert_stat(self.c.player_name, self.c.gamesWon, self.c.gamesPlayed)
            event.accept()
        else:
            event.ignore()   
    
app = QtGui.QApplication(sys.argv)
b_app = BlackjackApp()
app.exec_()
