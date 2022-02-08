### Iteration 1 - Doxygen Partial Assessment (Graded By: Subhankar Ghosh)

Run on March 30, 19:37:52 PM.

<hr>

This Partial Assessment indicates a TA has begun grading your Doxygen-generated documentation. However, documentation will be graded using a Canvas rubric and grades will only be posted on Canvas once every student's documentation has been graded. We ask for your patience at this time.

<hr>

+ Pass: Checkout iteration 1 final submission.




#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.


#### Doxygen Tests

+ Pass: Change into directory "project/docs".

+ Pass: Check that file "Doxyfile" exists.

+ Pass: Generating documentation by running doxygen

+ Pass: Check that file "html/index.html" exists.

+ Pass: Inspecting Doxygen webpages...



<hr>

This Partial Assessment indicates a TA has begun grading your branches and issues. However, this will be graded using a tallying spreadsheed and grades will only be posted to Canvas once every student's branches and issues have been graded. We ask for your patience at this time.

  Please note: Branches are counted throughout Iteration 1. We are looking for branches you made and left alone during Iteration 1. Issues however are counted for the entirety of the semester. We ran into some glitches automatically grading this, so this is the solution we came up with.

<hr>

+ Pass: Configuring GHI

+  _2_ / _2_ : Pass: This test counts the number of branches made during development of Iteration 1

Sufficient branches found (found=8, required=8):

add/11-bus-factory

add/12-skip-stops

add/14-regression-test

add/documentation

fix/02-google-style-errors

fix/08-compilation-errors

fix/09-pause-resume

fix/10-priority-1

+  _2.0_ / _2_ : Pass: Run ghi for total number of issues in Github repo (Found: 11, Expected: 8) 

 [OPEN issue #] : 

[CLOSED issue #12] :  Skip Stops

[CLOSED issue #11] :  Bus_Factory [enhancement]

[CLOSED issue #10] :  Priority Level 1

[CLOSED issue #9] :  Pause/Resume [enhancement]

[CLOSED issue #8] :  Simulator is not compiling [bug]

[CLOSED issue #7] :  Fix/02 google style errors ↑

[CLOSED issue #6] :  Fix/02 google style errors ↑

[CLOSED issue #5] :  fix(bus,config_manager, data_struct.h,passenger,passenger_factory, ↑

[CLOSED issue #4] :  fix(bus,config_manager, data_struct.h,passenger,passenger_factory, ↑

[CLOSED issue #2] :  Code Not in Google Style  [enhancement]

[CLOSED issue #1] :  Simulator Compile error [bug] 1

 




#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Amogh Bhagwat] 2020-03-24 (HEAD -> devel, tag: iteration1-final-devel, origin/devel, origin/add/14-regression-test, add/14-regression-test) - updating git ignore 

		[Amogh Bhagwat] 2020-03-24 Merge branch 'add/documentation' into devel - Merging the documentation part 

		[Amogh Bhagwat] 2020-03-24 (origin/add/documentation, add/documentation) fix(docs, bus.cc/.h, bus_factory.cc/h, config_manager.h, data_structs.h, large_bus.cc/h, mainpage.h, passenger.h, passenger_factory.h, passenger_generator.h, passenger_loader.h, passenger_unloader.h, random_passenger_generator, regular_bus.cc/h, small_bus.cc/h, route.h, stop.h, main.cpp, web_server_command, my_web_server_session.cc, visulzation_simulator.cc/h): fix #13 Add documentation - We added a main page, which talks about the bus simulator and factory
patterns. We also added documentation to the new classes and methods.
- We did this by using doxygen
- We also made the code google style guide compliant.


		[Amogh Bhagwat] 2020-03-22 Merge branch 'add/12-skip-stops' into devel - We added skip stopped functionalty 

		[Amogh Bhagwat] 2020-03-22 (origin/add/12-skip-stops, add/12-skip-stops) fix(bus.cc): fix #12 Added some code to show a stop has been skipped -In the bus move function I added two if statments if the passengers
handled is zero we say the stio has been skipped


		[Amogh Bhagwat] 2020-03-22 Merge branch 'add/11-bus-factory' into devel - Adding a bus factory 

		[Amogh Bhagwat] 2020-03-22 (origin/add/11-bus-factory, add/11-bus-factory) fix(bus.h, bus_factory.cc/h, large_bus.cc/h, regular_bus.cc/h, small_bus.cc/h, visualization_simulator.cc): fix #11 Added a bus factory - I added a bus factory wich creates small, regular, large
- Implmented this by making three derived class of bus
- Then I used a bus factory to with a switch statment to detemine
- which bus to make


		[Amogh Bhagwat] 2020-03-19 Merge branch 'fix/10-priority-1' into devel - Finished the priority 1 in the iteration 1 assignment 

		[Amogh Bhagwat] 2020-03-19 (origin/fix/10-priority-1, fix/10-priority-1) fix(bus.cc, passenger_loader.cc/.h, route.cc/.h, passenger_UT.cc, route_UT.cc, main.cpp): fix #10 fixed indentation in the bus.cc/.h and main.cc. I also changed the function NextStop to ToNextStop in various files that used it. I also changed LoadPassenger() to return a bool instead of int - We finished priority 1 from the requirements meaning indentation fixes
and a few function name and return statements changed. These changes
affected a few of the unit tests, so I went in and changed those too.


		[Amogh Bhagwat] 2020-03-18 Merge branch 'fix/09-pause-resume' into devel - We created a pause/resume button in a different branch, which pauses the sim when pressed and resumes when pressed again 

		[Amogh Bhagwat] 2020-03-18 (origin/fix/09-pause-resume, fix/09-pause-resume) fix(Sketch.js, Main.cpp, my_web_server_command.h, my_web_server_command.cc, visualization_simulator.cc/.h): fix #9 added pause button -We added code to the various files listed above. We firsted created a
pause button and then added functionality to it. We basically added a
boolen variable to toggle true and false eveytime it was pressed
-We added a pause button, socket.send, state.commend, Pausecommand in
web_server_command.cc/h, and a Pause() function in
visualization_simulator.cc/.h


		[Amogh Bhagwat] 2020-03-12 Reslove merge conflicts 

		[Amogh Bhagwat] 2020-03-11 remove 

		[Amogh Bhagwat] 2020-03-11 Merge branch 'support-code' of github.umn.edu:umn-csci-3084-s20/csci3081-shared-upstream into support-code 

		[Amogh Bhagwat] 2020-03-06 (tag: Iter1D2) files(bus_UT, route_UT, passenger_UT, stop_UT) -Added google test for Passenger constructor and public methods in the
- directory
-Added google test for bus, route, stop constructor and boolen return
-functions



		[Amogh Bhagwat] 2020-03-06 Adding google tests to tests dirc 


		[Amogh Bhagwat] 2020-03-05 Add(bus_UT.cc, route_UT.cc, stop_UT.cc, passenger_UT.cc - Added the first tests.
- Tested all public functions and constructor for passenger
- Tested all return boolen functions and constructor for bus, stop, route









		[Amogh Bhagwat] 2020-03-02 -ReadME was changed a little, so pushing inorder to make branch clean 

		[Amogh Bhagwat] 2020-03-02 Merge branch 'fix/02-google-style-errors' into devel -Fixed google style issues 

		[Amogh Bhagwat] 2020-03-02 (origin/fix/02-google-style-errors, fix/02-google-style-errors) fix(bus.cc, bus.h, config_manager.cc, config_manager.h, data_structs.h, passenger.h, passenger_factory.h, passenger_generator.h, passenger_loader.h, passenger_unloader.cc, passenger_unloader.h, random_passenger_generator.h): fix #2 "Code is upto google style guide" - I ran cpplint and corrected the google style issues that needed work
- I also changed a few elements of code in unloader and bus class
- I wrote a comment next to things I changed. Mainly pointer changes


		[Amogh Bhagwat] 2020-02-29 Merge branch 'fix/08-compilation-errors' into devel -uncommented some code 

		[Amogh Bhagwat] 2020-02-29 (origin/fix/08-compilation-errors, fix/08-compilation-errors) fix(bus,passenger,random_passenger_generator, stop): fix #8 "fixed commented codes" -Alot of code was commented out which were need in other parts of the code



		[Amogh Bhagwat] 2020-02-29 Add src to proj 

		[Amogh Bhagwat] 2020-02-29 Delete Src 



		[Amogh Bhagwat] 2020-02-25 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-bhagw018 

		[Amogh Bhagwat] 2020-02-25 Project 






		[Amogh Bhagwat] 2020-02-25 Project 


		[Amogh Bhagwat] 2020-02-25 Project 


		[Amogh Bhagwat] 2020-02-25 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-bhagw018 

		[Amogh Bhagwat] 2020-02-25 Project 


		[Amogh Bhagwat] 2020-02-25 Project 

		[Amogh Bhagwat] 2020-02-25 Project 

		[Amogh Bhagwat] 2020-02-25 Project 

		[Amogh Bhagwat] 2020-02-25 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-bhagw018 

		[Amogh Bhagwat] 2020-02-25 Project 



		[Amogh Bhagwat] 2020-02-25 Project 

		[Amogh Bhagwat] 2020-02-25 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-bhagw018 













		[Amogh Bhagwat] 2020-02-24 Merge branch 'support-code' 

		[Amogh Bhagwat] 2020-02-24 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream into support-code 



		[Amogh Bhagwat] 2020-02-24 Lab08 









+  _1_ / _1_ : Pass: Check git commit history
Sufficient commits (found=70,required=15)

