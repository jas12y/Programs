""" John Stubbs jas12y
    pylint 1.1.0
    Plots curves for
    final project """

import sys
from PyQt4 import QtGui

from matplotlib.backends.backend_qt4agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt4agg import NavigationToolbar2QT as NavigationToolbar
from matplotlib.figure import Figure
import numpy as np

class Plotter(QtGui.QMainWindow):
    """ Plotter class """
    def __init__(self, parent=None):
        """ Init """
        QtGui.QMainWindow.__init__(self, parent)
        self.curves = 0
        self.colors = ['b', 'r', 'g', 'y', 'm', 'k']
        self.create_main_frame()
        self.on_draw()

    def on_draw(self):
        """ Draw curve """
        if self.curves < 6:
            self.amp = float(self.amp_text.text())
            self.freq = float(self.freq_text.text())
            self. phi = float(self.phi_text.text())
            element = 2 * np.pi * self.freq
            x_axis = np.linspace(0, 2, 100)
            y_axis = self.amp * np.sin(element * x_axis + self.phi)
            self.axes.plot(x_axis, y_axis, self.colors[self.curves])
            self.axes.axis([0, 2, -1.5, 1.5])
            self.canvas.draw()
            self.curves += 1

    def create_main_frame(self):
        """ Main frame """
        self.main_frame = QtGui.QWidget()
        self.fig = Figure()
        self.canvas = FigureCanvas(self.fig)
        self.canvas.setParent(self.main_frame)
        self.axes = self.fig.add_subplot(111)
        self.mpl_toolbar = NavigationToolbar(self.canvas, self.main_frame)

        plot_btn = QtGui.QPushButton("Plot Sine Wave")
        clear_btn = QtGui.QPushButton("Clear")

        amp_lbl = QtGui.QLabel("Amplitude")
        self.amp_text = QtGui.QLineEdit()
        freq_lbl = QtGui.QLabel("Frequency")
        self.freq_text = QtGui.QLineEdit()
        phi_lbl = QtGui.QLabel("Phase")
        self.phi_text = QtGui.QLineEdit()
        plot_btn.clicked.connect(self.plot_action)
        clear_btn.clicked.connect(self.clear_action)

        vbox = QtGui.QGridLayout()
        vbox.addWidget(self.canvas, 0, 1)
        vbox.addWidget(self.mpl_toolbar, 1, 1)

        vbox.addWidget(amp_lbl, 2, 0)
        vbox.addWidget(self.amp_text, 2, 1)
        self.amp_text.setText("1")
        vbox.addWidget(freq_lbl, 3, 0)
        vbox.addWidget(self.freq_text, 3, 1)
        self.freq_text.setText("1")
        vbox.addWidget(phi_lbl, 4, 0)
        vbox.addWidget(self.phi_text, 4, 1)
        self.phi_text.setText("0")
        vbox.addWidget(plot_btn, 5, 0)
        vbox.addWidget(clear_btn, 5, 1)

        self.main_frame.setLayout(vbox)
        self.setCentralWidget(self.main_frame)

    def plot_action(self):
        """ Plot action """
        self.on_draw()

    def clear_action(self):
        """ Clear action """
        self.axes.cla()
        self.canvas.draw()
        self.curves = 0

app = QtGui.QApplication(sys.argv)
form = Plotter()
form.show()
app.exec_()
