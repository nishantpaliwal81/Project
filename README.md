# NE-Development Coding Test

Welcome.  If you have made it this far, you are progressing nicely in the 
interview process.  We have devised this little problem to see how well 
you can implement code in a timely manner.

The task is simple, we want you to implement a feed parser. How you choose
to do that is up to you but we do have a team with knowledge of this process
that agreed to write the test specs that you must conform to. 

We do not intend for this to be a arduous task and as such think that this
should roughly take 1-4 hours of work which includes any research. Please
try to refrain from going above and beyond the ask as well; we have a well
populated JIRA backlog that needs tackling before going rogue!

## System Requirements
- gcc (GCC) 4.8.3
- cmake version 3.10.2 or later
- GNU Make 3.82

NOTE: other versions may work on your local system but these are the versions your solution will be evaluated against.

## Building 
From the root of project directory (Hint: this file is in the root of the 
project directory) issue the following commands...

```
mkdir build
cd build
cmake ../.
make 
make test
```
## Inputs 

The exchange has a customer portal where example data can be found. We've downloaded
the example file they've provided and placed it in data/data.in. data.in is a binary 
file containing data exactly as if you received it from over the network but is NOT
a pcap.  The file has no header.  It contains multiple packets (Thousands actually).
Those packets can contain multiple messages.

NOTE: Please keep in mind that this data is in network byte order!

**All packets have the following header and contain a variable amount of messages:**

|Name               | Offset  |Length(bytes) |Type  |Description 
|-------------------|---------|--------------|------|--------------------------
|Num market updates |0        |2             |Int   |Number of market updates in this packet, immediately following this header 
|Packet length      |2        |2             |Int   |Length of the entire packet, including all of the updates as specified above and this header. 

**Quote messages are formatted as follows:**

|Name   |Offset |Length |Type    |Description 
|-------|-------|-------|--------|---------------------
|Length |0      |2      |Int     |Length of this message in bytes(include this length field) 
|Type   |2      |1      |Char    |“Q” 
|Dynamic data   |3   |Varies  |Char[]  |Quote data. Unused in this exercise, but dynamically sized. 

**Trade messages are formatted as follows:**

|Name   | Offset|Length |Type    |Description 
|-------|-------|-------|--------|---------------------
|Length |0      |2      |Int     |Length of this message in bytes(include this length field) 
|Type   |2      |1      |Char    |“T” 
|Symbol |3      |5      |Char[5] |Left justified character array with spaces in all unused bytes. 
|Trade Size |8  |2      |Int     |Volume of traded, ignore 
|Trade Price    |10 |8  |Float  |Price of traded volume, ignore 
|Dynamic     |18 |Varies  |Char[]  |Reserved, ignore 

## Outputs 
From the build directory...
```
make test
``` 

will run the tests.  If your output looks like this, they you are probably 
solved the problem.

```
$ make test
Running tests...
Test project /coding_test/build
    Start 1: runUnitTests
1/1 Test #1: runUnitTests .....................   Passed    0.02 sec
 
100% tests passed, 0 tests failed out of 1
 
Total Test time (real) =   0.02 sec
```
## Tasks 
To complete the task you will have to implement the following.

### 1) Implement the protocol parser
parser.cpp and parser.hpp contain the stub code to parse the feed. Implement
``GetMessagesInPacket`` and the unit test driver will call into your code with 
a valid ``MDCallback`` Implementation.  You may need to add implementation to
messages.cpp, which contain the classes you will be communicating with in step
two.

### 2) Complete the implementation of MDCallback interface
In ``filter.cpp`` there is an implementation of ``MDCallback`` called 
``MyCallback``.  The unit tests will inspect the methods on this class to check
for the expected values for the given output file.  If your parser is working
correctly, and you implement the correct tracking, in ``MyCallback`` the unit
tests will succeed.  ``GetQuoteCount`` has been left implemented as a sample.

### 4) Prepare to discuss your implementation
Once your code is complete the rest of your team will be eager to discuss
your implementation. They'll want to understand why you made the choices that
you did. 


## Project Files
### CMakeLists.txt
cmake build file.  You should not have to edit this.
### data/data.in
This is the raw data used in the test.  The path to this file will need to be 
parsed by you and processed.
### filter.cpp
The unit tests are contained in this file as well as the implementation of the
``MDCallback`` interface that is passed into your parser.
### googletest-release-1.10.0
Directory containing the unit test framework.  You will not need to edit this.
### messages.cpp and messages.hpp
Here we store the definitions and implementations of the Message objects used
to communicate through the MDCallbacks.  You may need to edit these to store 
state from your parsing.
### parser.cpp and parser.hpp
This is the home for the paser. The unit test create the parser and pass in the
path to the ``data.in`` file.  One of your jobs is to parse this file and call
into the callback.
### reader.hpp
The interface definition of the MDCallback.  
### README.md
This file.
