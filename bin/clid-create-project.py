#!/usr/bin/python

import sys.argv as args;
import os;
import shutil;

## This script is used to set up a project

#****************************************************
# DisplayHelp
# This is a function that gets called to display help
# information for the user
#****************************************************
def DisplayHelp():
    print("""
bide-mkproj - Create a new project with Best IDE.

usage:
bide-mkproj <project_name>
project_name should not have spaces in it

This will create a directory with the specified name and set up a project structure.
If the directory already exists, it will just add the bide project structure to the
existing directory. If the project structure already exists, no action will be taken.
""");

#***************************************************
# The main part of the script
# Do the right things
#***************************************************
if len(args) != 1:
    DisplayHelp();
    quit();

# Check to see if the first arguement exists in the current working dir
cwd = os.getcwd();
projDir = cwd + os.sep + args[0];
if os.access(projDir, os.F_OK) == False :
    os.mkdirs(projDir);
else :
    # Check to see if the bide proj structure exists
    commonDir = projDir + os.sep + "common";
    if os.access(commonDir, os.F_OK) == True :
        print("There already exists a project in " + str(projDir) + ". Doing nothing.");
        quit();

# We are free and clear to copy stuff into projDir

# Look up the location of the bide template structure from /etc/bide/bide.conf
file f = open("/etc/bide/bide.conf");
for line in f :
    if re.search("
