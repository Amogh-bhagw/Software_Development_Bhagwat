### Feedback for Lab 10

Run on March 02, 06:12:44 AM.


### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+ Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		bf222c52d6a6021533bc4b03936ddb3cd8cc04a4	refs/heads/devel

		bf222c52d6a6021533bc4b03936ddb3cd8cc04a4	refs/heads/fix/02-google-style-errors

		f8029a5b09f8d9bcec9d9bfad53eec3ce6bfbd89	refs/heads/fix/08-compilation-errors

		aeab6768bc4c5664fc01a50397f86fa85357e9d0	refs/heads/master



+ Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

fix/02-google-style-errors

fix/08-compilation-errors


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Amogh Bhagwat] 2020-02-29 (HEAD -> devel, origin/fix/02-google-style-errors, origin/devel, fix/02-google-style-errors) Merge branch 'fix/08-compilation-errors' into devel -uncommented some code 

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






















+ Pass: Check git commit history
Sufficient commits (found=27,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 1)

[OPEN issue #2] :  Code Not in Google Style  [enhancement]





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 6)

[CLOSED issue #8] :  Simulator is not compiling [bug]

[CLOSED issue #7] :  Fix/02 google style errors ↑

[CLOSED issue #6] :  Fix/02 google style errors ↑

[CLOSED issue #5] :  fix(bus,config_manager, data_struct.h,passenger,passenger_factory, ↑

[CLOSED issue #4] :  fix(bus,config_manager, data_struct.h,passenger,passenger_factory, ↑

[CLOSED issue #1] :  Simulator Compile error [bug] 1





+ Pass: Run ghi for total number of issues in Github repo (Found: 7, Expected: 2) 

 [OPEN issue #2] :  Code Not in Google Style  [enhancement]

[CLOSED issue #8] :  Simulator is not compiling [bug]

[CLOSED issue #7] :  Fix/02 google style errors ↑

[CLOSED issue #6] :  Fix/02 google style errors ↑

[CLOSED issue #5] :  fix(bus,config_manager, data_struct.h,passenger,passenger_factory, ↑

[CLOSED issue #4] :  fix(bus,config_manager, data_struct.h,passenger,passenger_factory, ↑

[CLOSED issue #1] :  Simulator Compile error [bug] 1

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+ Pass: Check that directory "project/src" exists.

+ Pass: Change into directory "project/src".

+ Pass: Check that file "makefile" exists.

+ Pass: Check that make compiles.



