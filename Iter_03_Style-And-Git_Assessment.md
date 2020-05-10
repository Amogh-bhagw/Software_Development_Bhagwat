### Iteration 3 - Style-And-Git Partial Assessment (Graded By: Subhankar Ghosh)

Run on May 10, 10:41:50 AM.

<hr>

This Partial Assessment indicates a TA has begun grading your Iteration 3 Design. However, design will be graded using a Canvas rubric and grades will only be posted on Canvas once every student's program design has been graded. We ask for your patience at this time.

<hr>

+ Pass: Checkout iteration 3 final submission.




#### Style Compliance Tests

+ Pass: Change into directory "project/src".

+ Pass: Linting main src files...



+ Pass: Change into directory "../web_code/web".

+ Fail: Linting web code...

<pre>Processing visualization_simulator.cc
Done processing /export/scratch/cpplint-ghosh117/web_code/web/visualization_simulator.cc
Total errors found: 0
Processing visualization_simulator.h
/export/scratch/cpplint-ghosh117/web_code/web/visualization_simulator.h:6:  #ifndef header guard has wrong style, please use: WEB_CODE_WEB_VISUALIZATION_SIMULATOR_H_  [build/header_guard] [5]
/export/scratch/cpplint-ghosh117/web_code/web/visualization_simulator.h:97:  #endif line should be "#endif  // WEB_CODE_WEB_VISUALIZATION_SIMULATOR_H_"  [build/header_guard] [5]
Done processing /export/scratch/cpplint-ghosh117/web_code/web/visualization_simulator.h
Total errors found: 2
Processing main.cpp
Done processing /export/scratch/cpplint-ghosh117/web_code/web/main.cpp
Total errors found: 0
Processing my_web_server.cc
Done processing /export/scratch/cpplint-ghosh117/web_code/web/my_web_server.cc
Total errors found: 0
Processing my_web_server.h
/export/scratch/cpplint-ghosh117/web_code/web/my_web_server.h:6:  #ifndef header guard has wrong style, please use: WEB_CODE_WEB_MY_WEB_SERVER_H_  [build/header_guard] [5]
/export/scratch/cpplint-ghosh117/web_code/web/my_web_server.h:25:  #endif line should be "#endif  // WEB_CODE_WEB_MY_WEB_SERVER_H_"  [build/header_guard] [5]
Done processing /export/scratch/cpplint-ghosh117/web_code/web/my_web_server.h
Total errors found: 2
Processing my_web_server_command.cc
Done processing /export/scratch/cpplint-ghosh117/web_code/web/my_web_server_command.cc
Total errors found: 0
Processing my_web_server_command.h
/export/scratch/cpplint-ghosh117/web_code/web/my_web_server_command.h:6:  #ifndef header guard has wrong style, please use: WEB_CODE_WEB_MY_WEB_SERVER_COMMAND_H_  [build/header_guard] [5]
/export/scratch/cpplint-ghosh117/web_code/web/my_web_server_command.h:153:  #endif line should be "#endif  // WEB_CODE_WEB_MY_WEB_SERVER_COMMAND_H_"  [build/header_guard] [5]
Done processing /export/scratch/cpplint-ghosh117/web_code/web/my_web_server_command.h
Total errors found: 2
Processing my_web_server_session.cc
Done processing /export/scratch/cpplint-ghosh117/web_code/web/my_web_server_session.cc
Total errors found: 0
Processing my_web_server_session.h
/export/scratch/cpplint-ghosh117/web_code/web/my_web_server_session.h:6:  #ifndef header guard has wrong style, please use: WEB_CODE_WEB_MY_WEB_SERVER_SESSION_H_  [build/header_guard] [5]
/export/scratch/cpplint-ghosh117/web_code/web/my_web_server_session.h:26:  #endif line should be "#endif  // WEB_CODE_WEB_MY_WEB_SERVER_SESSION_H_"  [build/header_guard] [5]
Done processing /export/scratch/cpplint-ghosh117/web_code/web/my_web_server_session.h
Total errors found: 2
Processing my_web_server_session_state.h
/export/scratch/cpplint-ghosh117/web_code/web/my_web_server_session_state.h:6:  #ifndef header guard has wrong style, please use: WEB_CODE_WEB_MY_WEB_SERVER_SESSION_STATE_H_  [build/header_guard] [5]
/export/scratch/cpplint-ghosh117/web_code/web/my_web_server_session_state.h:20:  #endif line should be "#endif  // WEB_CODE_WEB_MY_WEB_SERVER_SESSION_STATE_H_"  [build/header_guard] [5]
Done processing /export/scratch/cpplint-ghosh117/web_code/web/my_web_server_session_state.h
Total errors found: 2
Processing web_interface.h
/export/scratch/cpplint-ghosh117/web_code/web/web_interface.h:6:  #ifndef header guard has wrong style, please use: WEB_CODE_WEB_WEB_INTERFACE_H_  [build/header_guard] [5]
/export/scratch/cpplint-ghosh117/web_code/web/web_interface.h:20:  #endif line should be "#endif  // WEB_CODE_WEB_WEB_INTERFACE_H_"  [build/header_guard] [5]
Done processing /export/scratch/cpplint-ghosh117/web_code/web/web_interface.h
Total errors found: 2
</pre>




#### Git Tests

+  _1.0_ / _2_ : Pass: Counting Iteration 3 branches...

Insufficient branches found (found=3, required=6):

Add/20-Documentation-3

add/19-stop-decorate

add/singleton-pattern

+  _2.0_ / _2_ : Pass: Run ghi for total number of issues in Github repo (Found: 4, Expected: 4) 

 [OPEN issue #] : 

[CLOSED issue #20] :  Documentation 3  [bug]

[CLOSED issue #19] :  Stop observation and Decorating pattern [enhancement]

[CLOSED issue #18] :  Singleton Pattern [enhancement]

[CLOSED issue #17] :  Adding Documentation iteration 2 [enhancement]

 




#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Amogh Bhagwat] 2020-05-01 (HEAD, tag: Iter3-master) Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-bhagw018 

		[Amogh Bhagwat] 2020-05-01 Merge branch 'devel' 

		[Amogh Bhagwat] 2020-05-01 (tag: Iter3-devel, origin/devel) Merge branch 'Add/20-Documentation-3' into devel 

		[Amogh Bhagwat] 2020-05-01 (origin/Add/20-Documentation-3, Add/20-Documentation-3) fix (FileWriter.h, FileWriterManager.cc/h, IObservable.h, Util.h, data_structs.h, mainpage.h, passenger.cc, my_web_server.cc/h, my_web_server_session.h/cc, my_web_server_session_state.h, visualization_simulator.cc/h): fix #20 Add documentation and google style fixes - We added a discussion of decorator pattern to the main page
- Fixed google style complients
- Added comments to new classes and methods


		[Amogh Bhagwat] 2020-04-30 Merge branch 'add/singleton-pattern' into devel 

		[Amogh Bhagwat] 2020-04-30 (origin/add/singleton-pattern, add/singleton-pattern) fix(FileWriter.h, FileWriterManager.cc/h, Util.h, bus.cc/h, passenger_unloader.cc/h, visualization_simulator.cc/h) : fix #18 Added a singleton pattern to generate stats for bus and passenger - We added a singleton pattern, which is FileWriterManager and
FileWriter.
- We also added a Util class, which helped structure the strings that
will be passed in
- Created three new variables one in bus, one in passenger_unloader, and
one in visualization_simulator


		[Amogh Bhagwat] 2020-04-27 Merge branch 'add/19-stop-decorate' into devel 

		[Amogh Bhagwat] 2020-04-27 (origin/add/19-stop-decorate, add/19-stop-decorate) fix(IObservable.cc/h, IObserver.h, bus.cc/h, data_structs.h, r_local_simulator0.h, stop.cc/h, main.cpp, my_web_server.cc, my_web_server_command.cc/h) : fix #19 Added a stop observer and colored busses - We made the IObserver a template and added a stop observer.
- We added color to the busses and depending on the passengers it gets
darker


		[Amogh Bhagwat] 2020-04-22 Just making eveything up to date 







+  _1_ / _1_ : Pass: Check git commit history
Sufficient commits (found=21,required=10)

+ Pass: Opening Iter_03_Style-And-Git_Assessment.md using firefox

