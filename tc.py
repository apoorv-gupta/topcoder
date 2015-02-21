import sys
def calc(f):
 tt=4500
 pt=0
 while True:
  num = 0.7*tt*tt
  den = 10*pt*pt+tt*tt
  val=0.3+num/den
  if(val<f):
   print str(pt/60) + " minutes " + str(pt%60) + " seconds for "+ str(f)+" points"
   return pt
  pt = pt + 1

if(len(sys.argv)>4):
 print "needs three arguments: 250 500 1000"
 sys.exit(0);
val=0
if(len(sys.argv)>1):
 val += calc(float(sys.argv[1])/250)
if(len(sys.argv)>2):
 val += calc(float(sys.argv[2])/500)
if(len(sys.argv)>3):
 val += calc(float(sys.argv[3])/1000)

if(val>4500):
 print "You would have exceeded by "+str(1+((val-4500)/60))+" minutes"
elif((val<4500) and (len(sys.argv)==4)):
 print "Congrats! You could have been a Stud!"
else:
 print "You would have taken "+str(1+((val)/60))+" minutes"

