# GitHub Examples

<!-- [![Build Status](https://travis-ci.org/aleman/hw01.svg?branch=master)](https://travis-ci.org/aleman/hw01) -->

## Base case: 1 person makes changes on the default branch: master.
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

  ![!case1d](img/case-2-d.png?raw=true)

Anna gets the new branch locally via: `git pull --all`

The output looks like: 

```
   Fetching origin
     From https://github.com/aleman/hw01
     * [new branch]      hotfix-T1104 -> origin/hotfix-T1104
     Already up-to-date.
```

Anna switches to the newly created branch via: `git checkout hotfix-T1104`

After editing/changing things, the files that changed can be listed via: `git status`

The output would list files in the following manner (example)

```
On branch hotfix-T1104
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

no changes added to commit (use "git add" and/or "git commit -a")
```

Anna marks all files to be part of the repo via: `git add \*`

Anna then creates a commit locally, via: `git commit -m "Fixed, config updated and few files added"`

The output will look similar to:
```
[hotfix-T1104 73c7dc4] Fixed, config updated and few files added
 5 files changed, 76 insertions(+), 2 deletions(-)
 ```

The commit point is created but one more step is needed to copy it to GitHub: `git push origin hotfix-T1104`

The output will look similar to:
```
Counting objects: 8, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (8/8), done.
Writing objects: 100% (8/8), 245.20 KiB | 0 bytes/s, done.
Total 8 (delta 1), reused 0 (delta 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local objects.
To https://github.com/aleman/hw01.git
   0f10e2..737d4  hotfix-T1104 -> hotfix-T1104
```

The updated graph shows the branch `hotfix-T1104` ahead of the `master` branch


### Option 1: integrate the commit via rebase

Anna's branch hotfix-T1104 is up to date locally.

Switch to the master branch via: `git checkout master`

The output will look similar to: 
```
Switched to branch 'master'
Your branch is up-to-date with 'origin/master'.
```

Make sure that we update the local copy with the latest from GitHub, via: `git pull origin master`

The output will look similar to:
```
From https://github.com/aleman/hw01
 * branch            master     -> FETCH_HEAD
Already up-to-date.
```

Rebase master with respect to the branch hotfix-T1104, via: `git rebase hotfix-T1104`

The output will look similar to:
```
First, rewinding head to replay your work on top of it...
Fast-forwarded master to hotfix-T1104.
```

This will apply the commit(s) of branch hotfix-T1104 on top of master.

Verify the status via: `git status`

The output will look similar to:
```
On branch master
Your branch is ahead of 'origin/master' by 1 commit.
  (use "git push" to publish your local commits)
nothing to commit, working tree clean
```

The local version of `master` is 1 commit ahead than origin (that is, GitHub). 
Push the local commit to the `master` branch on GitHub via: `git push origin master`

The output will look similar to:

```
Total 0 (delta 0), reused 0 (delta 0)
To https://github.com/aleman/hw01.git
   0f20e32..73c7dc4  master -> master
```

### Option 2: integrate the commit via pull-request


