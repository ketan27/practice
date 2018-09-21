from sys import argv
from os.path import exists

script, from_file, to_file = argv

print "Copying from %s to %s" % (from_file, to_file)

indata = open(from_file).read()

print "The input file is %d bytes long" % len(indata)

print "Does the output file exists? %r" % exists(to_file)
print "Ready, hit RETURN to continue, CTRL-C to abort."
raw_input()

# Can be shortened as well
out_file = open(to_file, 'w').write(indata)
#out_file.write(indata)

print "All done!."

# No need to close in such cases
#out_file.close()
