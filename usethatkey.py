string = raw_input('Insert hexadecimal string')
message = raw_input('Enter known message')
tocipher = raw_input('Now you will get the key. Introduce the text to encrypt')

def strxor(s1,s2):
	return ''.join(chr(ord(a) ^ ord(b)) for a,b in zip(s1,s2))

print strxor(strxor(string.decode('hex'), message), tocipher).encode('hex')
