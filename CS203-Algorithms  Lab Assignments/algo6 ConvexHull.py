import matplotlib.pyplot as plt
IX,IY,OX,OY=[],[],[],[]
with open("fileIn.txt","r") as file2:
	i=0
	for line in file2:
		if(i==0):
			i=i+1
			continue
		if(line):
			x,y=line.strip().split()
			IX.append(int(x))
			IY.append(int(y))
with open("fileOut.txt","r") as file1:
	for line in file1:
		if(line):
			x,y,z=line.strip().split()
			OX.append(x)
			OY.append(y)
plt.plot(IX,IY,'bo')
plt.plot(OX,OY,'r')
plt.show()

