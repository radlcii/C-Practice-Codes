#!/bin/sh
# Written by Robert De La Cruz II
# Written on Jan 6 2019
# This is a shell script to backup my personal C projects from their main directory to another one.
# Done to keep the backups away from GNU make
cp main ./*.c ./*.h *.sh ~/cProgsBackups

