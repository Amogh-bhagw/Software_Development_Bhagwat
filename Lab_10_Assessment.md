### Assessment for Lab 10

#### Total score: _100.0_ / _100_

Run on March 03, 13:17:58 PM.


### Necessary Files and Structure

+  _10_ / _10_ : Pass: Check that directory "labs" exists.

+  _10_ / _10_ : Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+  _10_ / _10_ : Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		2c80abe051617df37381dd80074ee73dab931e18	refs/heads/devel

		354faa4187361869306836e1a8a33ccb7e3c6c39	refs/heads/fix/02-google-style-errors

		f8029a5b09f8d9bcec9d9bfad53eec3ce6bfbd89	refs/heads/fix/08-compilation-errors

		ae2c075fefc2312f2ae891125239b612c473decd	refs/heads/master



+  _10_ / _10_ : Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

fix/02-google-style-errors

fix/08-compilation-errors


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Amogh Bhagwat] 2020-03-02 (HEAD -> devel, origin/devel) -ReadME was changed a little, so pushing inorder to make branch clean 

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















		[Amogh Bhagwat] 2020-02-23 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-bhagw018 

		[Amogh Bhagwat] 2020-02-23 lab08 



		[Amogh Bhagwat] 2020-02-22 lab08 


		[Amogh Bhagwat] 2020-02-22 lab08 




















		[Amogh Bhagwat] 2020-02-21 Lab 8 

		[Amogh Bhagwat] 2020-02-21 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-bhagw018 






















+  _5_ / _5_ : Pass: Check git commit history
Sufficient commits (found=33,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of closed issues in Github repo (Found: 7)

[CLOSED issue #8] :  Simulator is not compiling [bug]

[CLOSED issue #7] :  Fix/02 google style errors ↑

[CLOSED issue #6] :  Fix/02 google style errors ↑

[CLOSED issue #5] :  fix(bus,config_manager, data_struct.h,passenger,passenger_factory, ↑

[CLOSED issue #4] :  fix(bus,config_manager, data_struct.h,passenger,passenger_factory, ↑

[CLOSED issue #2] :  Code Not in Google Style  [enhancement]

[CLOSED issue #1] :  Simulator Compile error [bug] 1





+  _10.0_ / _10_ : Pass: Run ghi for total number of issues in Github repo (Found: 7, Expected: 2) 

 [OPEN issue #] : 

[CLOSED issue #8] :  Simulator is not compiling [bug]

[CLOSED issue #7] :  Fix/02 google style errors ↑

[CLOSED issue #6] :  Fix/02 google style errors ↑

[CLOSED issue #5] :  fix(bus,config_manager, data_struct.h,passenger,passenger_factory, ↑

[CLOSED issue #4] :  fix(bus,config_manager, data_struct.h,passenger,passenger_factory, ↑

[CLOSED issue #2] :  Code Not in Google Style  [enhancement]

[CLOSED issue #1] :  Simulator Compile error [bug] 1

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+  _10_ / _10_ : Pass: Check that directory "project/src" exists.

+ Pass: Change into directory "project/src".

+  _5_ / _5_ : Pass: Check that file "makefile" exists.

+  _30_ / _30_ : Pass: Check that make compiles.



#### Total score: _100.0_ / _100_

