#!/bin/bash

TEMP_DIRECTORY="../../programming-club-cpy"
COMMIT_MESSAGE="Add"
MAX_FILES=5
BRANCH=$(git branch | awk '{print $2}')

function update_hash() {
	

}

#TODO: modified files, can do with md5

if [ ! -d "${TEMP_DIRECTORY}" ] ; then
	echo "Creating directory ${TEMP_DIRECTORY}"
	cp -r $PWD $TEMP_DIRECTORY
	exit 0
fi

FILES_LIST=$(ls $PWD)
TOTAL_ADDED_FILES=0

#if [ $1 == "-m" ] ; then 
	#find /dir1/ -type f -exec md5sum {} + | sort -k 2 > files.hash
	
#fi

for file in $FILES_LIST
do
	if ! ls $TEMP_DIRECTORY | grep -q $file ; then #TODO: != gitignore files
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
	rm -r -f $TEMP_DIRECTORY && cp -r -a $PWD/. $TEMP_DIRECTORY
	exit 0
else
	echo "Nothing to commit"
fi
