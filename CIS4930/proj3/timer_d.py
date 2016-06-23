""" John Stubbs jas12y
    This module times an arbitrary
    function with no arguments. """

import time

def t_decorator(func):
    """ Decorator to time function """
    def mytimer():
        """ The timer """
        start_time = time.time()
        func()
        end_time = time.time()
        return "Time to execute function (s): " + str(end_time-start_time)

    return mytimer
