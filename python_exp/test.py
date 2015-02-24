import csv;
import sys;

def tupleToTime(t):
    return str(t[0]) + "h:" + str(t[1]) + "m";

class Result:
    def __init__(self,row):
        self.repeat = 1;
        self.key = row[1] + " " + row[2] + " " + row[4];
        self.totalTime = 0;
        self.maxTime = (0,0);
        self.minTime = (99,99);
        self.moreThan10 = set([]);
        self.moreThan20 = set([]);
        self.moreThan30 = set([]);

        self.updatePatchTime(row);

    def updatePatchTime(self,row):
        time = row[13].split(":")
        hours = 0;
        mins = 0;

        if (len(time) == 2):
            hours = int(time[0][:-1]);
            mins = int(time[1][:-1]);

        self.totalTime = self.totalTime + (60*hours) + mins;

        if ((hours,mins) > (10,0)):
            #self.moreThan10 = self.moreThan10 + 1;
            self.moreThan10.add(row[6]);

        if ((hours,mins) > (20,0)):
            #self.moreThan20 = self.moreThan20 + 1;
            self.moreThan20.add(row[6]);

        if ((hours,mins) > (30,0)):
            #self.moreThan30 = self.moreThan30 + 1;
            self.moreThan30.add(row[6]);

        if ((hours,mins) > self.maxTime):
            self.maxTime = (hours,mins);

        if ((hours,mins) < self.minTime):
            self.minTime = (hours,mins);

    def update(self,row):
        self.repeat = self.repeat + 1;
        self.updatePatchTime(row);
        

    def __str__(self):

        avgMins = self.totalTime / self.repeat;
        mins = avgMins%60;
        hours = avgMins/60;
        avgTime = (hours,mins);

        return str(self.repeat) + " " + str(self.moreThan10) + " " + \
            str(self.moreThan20) + " " + str(self.moreThan30) + " " + \
            tupleToTime(self.maxTime) + " " + tupleToTime(self.minTime) + " " +\
            tupleToTime(avgTime);

    def __repr__():
        return "";

def parse(csvFile):
    d = {};
    with open(csvFile, 'rb') as f:
        reader = csv.reader(f)
        reader.next();
        for row in reader:
            key = row[1] + " " + row[2] + " " + row[4];
            if key not in d:
                d[key] = Result(row);
            else:
                val = d[key];
                val.update(row);
            #print row
        for k,v in d.iteritems():
            print k + " " + str(v);

def main():
    if len(sys.argv) != 2:
        print "invalid args";
        return;

    inputFile = sys.argv[1];
    parse(inputFile);

if __name__ == "__main__":
    main();
