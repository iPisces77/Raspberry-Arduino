
from flask import Flask, request, session, g, redirect, url_for, abort, render_template, flash
from contextlib import closing
from pi_car import app 
import re
import RPi.GPIO as GPIO
import serial
port_serial="/dev/ttyACM0"  
sl = serial.Serial(port_serial,9600) 
@app.route('/')
def show_index():
	return render_template('home.html')

@app.route("/login", methods=["GET", "POST"])                                
def login():                                                                    
	if request.method=="GET":                                                   
		return "get"+request.form["user"]
	elif request.method=="POST":                                                
		return "post"

@app.route('/ctl',methods=['GET','POST'])
def ctrl_id():
	if request.method == 'POST':
		id=request.form['id']
		if id == 'forward':
			Forward()
			return "up"
		elif id == 'back':
			Back()
			return "down"
		elif id == 'right':
			Right()
			return "right"
		elif id == 'left':
			Left()
			return "left"
		elif id == 'stop':
			Stop()
			return "stop"

	return redirect(url_for('show_index'))

def Forward():
	string="1"
	sl.write(string)
	
def Back():
	string="2"
	sl.write(string)

def Right():
	string="3"
	sl.write(string)

def Left():
	string="4"
	sl.write(string)


def Stop():
	string="0"
	sl.write(string)
