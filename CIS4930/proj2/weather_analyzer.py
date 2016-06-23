""" John Stubbs jas12y
    This module defines the weather_analyzer function
    for analyzing a file of weater statistics. """
from __future__ import print_function

CONVERT = lambda num: (float(num) / 10) * 1.8 + 32

def get_diff(max_num, min_num):
    """Returns the temperature difference"""
    diff = CONVERT(max_num) - CONVERT(min_num)
    return diff

def weather_analyzer():
    """The weather_analyzer function opens a file in the local
    directory, parses the file and returns the max temperature,
    max-min temperature, average wind speed, and total precipitation.
    """

    infile = raw_input('File to be analyzed (.csv only): ')

    # Open file and read attribute names
    csv_f = open(infile, 'r')
    attr_names = csv_f.readline().split(',')

    # Grab indeces of interesting attributes
    try:
        tmax_index = attr_names.index("TMAX")
        tmin_index = attr_names.index("TMIN")
        awnd_index = attr_names.index("AWND")
        prcp_index = attr_names.index("PRCP")
        date_index = attr_names.index("DATE")
    except Exception as err:
        print("Error: ", err)

    tmax_list = []
    tdif_list = []
    awnd_list = []
    prcp_list = []
    date_list = []
    for line in csv_f:
        line = line.split(',')
        tmax_list.append(CONVERT(line[tmax_index]))
        tdif_list.append(get_diff(line[tmax_index], line[tmin_index]))
        awnd_list.append(line[awnd_index])
        prcp_list.append(line[prcp_index])
        date_list.append(line[date_index])

    tmax = 0
    tdif = 1000
    for i in range(len(tmax_list)):
        max_val = tmax_list[i]
        if max_val > tmax:
            tmax = max_val
            max_date = date_list[i]
        min_val = tdif_list[i]
        if min_val < tdif:
            tdif = min_val
            min_date = date_list[i]

    awnd = [float(x) for x in awnd_list]
    wind = (sum(awnd) / len(awnd)) / 10
    prcp = [float(x) for x in prcp_list]
    p_total = sum(prcp) / 10
    print("Maximum temperature (F): ", tmax, " on " +
    max_date[4:6] + "/" + max_date[6:] + "/" + max_date[:4])
    print("Minimum temperature difference (F): ", tdif, " on " +
    min_date[4:6] + "/" + min_date[6:] + "/" + min_date[:4])
    print("Average wind speed (m/s): ", round(wind, 2))
    print("Total precipitation (mm): ", p_total)

if __name__ == "__main__":
    weather_analyzer()

