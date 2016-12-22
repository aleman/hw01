# hw01

<!-- [![Build Status](https://travis-ci.org/aleman/hw01.svg?branch=master)](https://travis-ci.org/aleman/hw01) -->

Base case: 1 person makes changes on the default branch: master.
![image](img/case-1.png?raw=true)

## Anna: please fix the ticket on a new branch

Anna creates new branch.

  * click on button: Branch: master
	![!case1a](img/case-2-a.png?raw=true)

  * type the name of the branch: hotfix-T1104
  * the **blue** selection changes to give option to: Create branch: hotfix-T1104
  * click on that selection
	![!case1b](img/case-2-b.png?raw=true)

  * the page then says "Branch created", it shows you that the current branch you're looking at is "hotfix-T1104", and it indicates that "The branch is even with master"
	![!case1c](img/case-2-c.png?raw=true)

  * You can see the "Graph" (selecting Graps, then Network) where branches 'master', and 'hotfix-T1104' are even: they point to the same commit
	![!case1c](img/case-2-c.png?raw=true)

Anna gets the new branch locally via: `git pull --all`

The output looks like: 
```Fetching origin
From https://github.com/aleman/hw01
 * [new branch]      hotfix-T1104 -> origin/hotfix-T1104
 Already up-to-date.```

Anna switches to the newly created branch via: `git checkout hotfix-T1104`

After editing/changing things, the files that changed can be listed via: `git status`
The output would list files in the following manner (example)
```On branch hotfix-T1104
Your branch is up-to-date with 'origin/hotfix-T1104'.
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

    	modified:   config.txt

 Untracked files:
   (use "git add <file>..." to include in what will be committed)

    	  	img/logo.png
    	  	img/background.png
    	  	src/authenticate.php
    	  	src/signoff.php

no changes added to commit (use "git add" and/or "git commit -a")```

Anna marks all files to be part of the repo via: `git add \*`

Anna then creates a commit locally, via: `git commit -m "Fixed, config updated and few files added"`

The commit point is created but one more step is needed to copy it to GitHub: `git push origin hotfix-T1104`

### Option 1: integrate the commit via rebase

Anna's branch hotfix-T1104 is up to date locally.

Switch to the master branch via: `git checkout master`

Make sure that we update the local copy with the latest from GitHub, via: `git pull origin master`

Rebase master with respect to the branch hotfix-T1104, via: `git rebase hotfix-T1104`

This will apply the commit(s) of branch hotfix-T1104 on top of master.

Verify the status via: `git status`

The local version of `master` is 1 commit ahead than origin (that is, GitHub). 
Push the local commit to the `master` branch on GitHub via: `git push origin master`

### Option 2: integrate the commit via pull-request


