

def main():
	print("careful with inputs larger than 6")
	x = int(input("x = "))
	pFile = open("primes.txt","w+")
	maxRange = pow(10,x)
	primes = [];
	for n in range(2,maxRange):
		newP = 1
		for p in primes:
			if(n%p==0):
				newP = 0
				break
		if(newP!=0):
			primes.append(n)

	i=1
	twins = 0
	sizePrimes = len(primes)

	for p in primes:
		if(i<sizePrimes):
			if(primes[i]-primes[i-1]==2):
				twins = twins + 1
		i=i+1
	pFile.write("# of twins between 2-" + str(maxRange) + ": " + str(twins) + "\n")

	i=1
	for p in primes:
		if(i<sizePrimes):
			if(primes[i]-primes[i-1]==2):
				twins = twins + 1
		pFile.write(str(i) + ". " + str(p) + "\n")
		i=i+1


main()