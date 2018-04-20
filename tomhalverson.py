for i in range(1,101):
	if(i%4==0 and i%7==0):
		print("#%d Tom Halverson"%i)
	elif(i%4==0):
		print("#%d Tom"%i)
	elif(i%7==0):
		print("#%d Halverson"%i)
	else:
		print("#.")

