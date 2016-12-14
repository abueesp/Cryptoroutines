
import re

MSGS = raw_input('Enter ciphertexts vector')
MSGTODECIPHER = raw_input('Enter scope ciphertext to decrypt')

charset = '^['+"a-zA-Z ."+']+$'

while True:
	indexer = []
	response = raw_input('Introduce new crib: ')
	crib = str(response)
	ponse = raw_input("From message (let's choose f.i. 1 if not from message): ")
	indexer = int(ponse)

	def strxor(s1,s2):
		return ''.join(chr(ord(a) ^ ord(b)) for a,b in zip(s1,s2))

	lastxor = []
	for element_index, message in enumerate(list(MSGS)): 
		for element in MSGS:
			xor = strxor(strxor(message.decode('hex'), element.decode('hex')), crib)
			if (re.search(charset,xor)):
			    if not xor == crib:
				if not xor in lastxor:			    	
					print 'Message ' + str(element_index) + ': ' + str(xor)	
					lastxor.append(xor)
	print "Matches with message number" + str(indexer) + ' | ' + str(lastxor)
	key = strxor(MSGTODECIPHER.decode('hex'), crib)	
	print 'Your key is: ' + str(key)
	decipherxor = strxor('MSGTODECIPHER'.decode('hex'), key)	
	print 'Your message is: ' + str(decipherxor)

	print 'Repeating with key'
	for msg in MSGS:
		result = strxor(msg.decode('hex'), key)
		print result
	
