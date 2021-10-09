#!/bin/bash

TEMP_DIRECTORY="../programming-club-cpy"
COMMIT_MESSAGE="Add"
MAX_FILES=5
BRANCH="master"

if [ ! -d "${TEMP_DIRECTORY}" ] ; then
	echo "Creating directory ${TEMP_DIRECTORY}"
	cp -r $PWD $TEMP_DIRECTORY
	exit 0
fi

FILES_LIST=$(ls $PWD)
TOTAL_ADDED_FILES=0

for file in $FILES_LIST
do
	if ! ls $TEMP_DIRECTORY | grep -q $file ; then
		((TOTAL_ADDED_FILES=TOTAL_ADDED_FILES+1))
		COMMIT_MESSAGE+=" $file"
	fi
	if [ $TOTAL_ADDED_FILES -gt 5 ] ; then
		COMMIT_MESSAGE+=" and others..."
		break
	fi
done

if [ $TOTAL_ADDED_FILES != 0 ] ; then
	echo "Commiting to remote branch ${BRANCH} with message ${COMMIT_MESSAGE}"
	git add *
	git commit -m "${COMMIT_MESSAGE}"
	git pull --rebase
	git push origin $BRANCH
	rm -r $TEMP_DIRECTORY && cp -r -a $PWD/. $TEMP_DIRECTORY
	exit 0
else
	echo "Nothing to commit"
fi
