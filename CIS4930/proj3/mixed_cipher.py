""" John Stubbs jas12y
    This module takes in a keyword and
	encrypts a text file. """

from __future__ import print_function
import sys, string

def convert(objin, cipher):
    """ Converts character """
    capital = False
    if objin.isupper():
        capital = True
    pch = cipher[objin.lower()]
    if capital:
        print(pch.upper(), end="")
    else:
        print(pch, end="")

def remove_extra(lst):
    """ Removes extra charaters	"""
    rlst = []
    seen = set()
    for element in lst:
        if element not in seen:
            rlst.append(element)
            seen.add(element)
    return rlst

def get_cipher():
    """ Gets keyword and
        generate cipher. """

    # Get keyword from user
    keyword = raw_input('Please enter a keyword for the mixed cipher: ')
    print("Plaintext: ", string.ascii_lowercase)
    # Remove extra charaters
    output = remove_extra(list(keyword.lower()) + list(string.ascii_lowercase))
    print("Ciphertext: ", ''.join(output))
    drtn = dict(zip(list(string.ascii_lowercase), output))
    return drtn

def mixed_cipher():
    """ Opens a file and encrypts
        the text. """

    if len(sys.argv) != 2:
        sys.exit('Usage: mixed_cipher.py <filename>')

    cipher = get_cipher()
    input_file = open(sys.argv[1], 'r')

    for line in input_file:
        for objin in line:
            if objin.isalpha():
                convert(objin, cipher)
            else:
                print(objin, end="")

if __name__ == "__main__":
    mixed_cipher()
