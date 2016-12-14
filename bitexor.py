#!/usr/bin/python

import sys
import re
import argparse

def sxor(ctext,crib):    
    # convert strings to a list of character pair tuples
    # go through each tuple, converting them to ASCII code (ord)
    # perform exclusive or on the ASCII code
    # then convert the result back to ASCII (chr)
    # merge the resulting array of characters as a string
    results = []
    single_result = ''
    crib_len = len(crib)
    positions = len(ctext)-crib_len+1
    for index in xrange(positions):
        single_result = ''
        for a,b in zip(ctext[index:index+crib_len],crib):
            single_result += chr(ord(a) ^ ord(b))
        results.append(single_result)
    return results

def print_linewrapped(text):
    line_width = 40
    text_len = len(text)
    for chunk in xrange(0,text_len,line_width):
        if chunk > text_len-line_width:
            print str(chunk) + chr(9) + text[chunk:]
        else:
            print str(chunk) + chr(9) + text[chunk:chunk+line_width]



parser = argparse.ArgumentParser(description='Bite your XOR')
parser.add_argument('ciphertext', help='Ciphertext, encoded in an ASCII hex format (ie. ABC would be 414243)')
parser.add_argument('-c', '--charset', help='A regex-style character set to be used to identify best candidates for successful decryption (ex: for alphanumeric characters and spaces, use "a-zA-Z0-9 ")', default='a-zA-Z0-9.,?! :;\'"')
args = parser.parse_args()

ctext = args.ciphertext.decode('hex')
ctext_len = len(ctext)
display_ctext = "_" * ctext_len
display_key = "_" * ctext_len

charset = '^['+args.charset+']+$'
seen = []
seenpositions = []
counter = 0
seenrepeated = []
seenrepeatedpositions = []
response = ''
while response != 'end':
	print "Your message is currently:"
	print_linewrapped(display_ctext)
	print "Your key is currently:"
	print_linewrapped(display_key)
	crib = raw_input("Please enter your crib: ")
	crib_len = len(crib)

	results = sxor(ctext, crib)
	results_len = len(results)
	seen = []
	seenpositions = []
	seenrepeated = []
	seenrepeatedpositions = []
	#Generate results
	print "ALL XOR RESULTS"
	for result_index in xrange(results_len): 
            if (re.search(charset,results[result_index])):
		    print '*** ' + str(result_index) + ': "' + results[result_index] + '"'
            else:
		    print str(result_index) + ': "' + results[result_index] + '"'

	print "POSSIBLE MATCHS"
	for result_index in xrange(results_len): 
            if (re.search(charset,results[result_index])):
		    found = str(results[result_index])
		    found_index = str(result_index)
		    if found in seen:
			repeated = found
			repeated_index = result_index
			for index, term in enumerate(seen):
				if term == repeated:				
					seenrepeatedpositions.append(seenpositions[index])
			seenrepeatedpositions.append(found_index)
			seenrepeated.append(found)
		        print "Keys or messages repeated! :" + '*** ' + str(repeated_index) + ': "' + found
		    print '*** ' + str(result_index) + ': "' + results[result_index] + '"'
		    seenpositions.append(found_index)
		    seen.append(found)
		
	print 'All posible matchs:' + str(seen)
	print 'All positions:' + str(seenpositions)

	print 'All repeated:' + str(seenrepeated)
	print 'All repeatedpositions:' + str(seenrepeatedpositions)
	
	ponse = raw_input("Do you want to iterate the xor based on results? y/n: ")
	if ponse == 'y':
	#Replace part of the message or key
		for keys_index, keys in enumerate(list(seen)):
		    keyresults = sxor(ctext, keys)
		    keyresults_len = len(keyresults)
		    print '*** Position of result' + ': Result ' + ' | Iterated result ' +  ' | Position of iterated result' + ' | Iterated result '
		    for keyresult_index in xrange(keyresults_len): 
        	    	if (re.search(charset,keyresults[keyresult_index])):
				    keyfound = str(keyresults[keyresult_index])
				    keyfound_index = str(keyresult_index)
				    print '*** ' + str(seenpositions[keys_index]) + ' : ' + str(keys) +  ' | ' + str(keyfound_index) + ' | ' + str(keyfound) 
	
	response = raw_input("Enter the position, or enter 'all' for all matchs, 'rep' for all repeated matchs, 'end' to quit, or anything else for no match and repeat process: ")

	#Replace part of the message or key
	try:
		if str(response) == 'all':
			message_or_key = ''
			while (message_or_key != 'm' and message_or_key != 'k'):
				message_or_key = raw_input("Is this crib part of the message or key? Please enter 'm' or 'k': ")
				if(message_or_key == 'm'):
					for element in list(seenpositions):
						element = int(element)
						display_ctext = display_ctext[:element] + crib + display_ctext[element+crib_len:]
						display_key = display_key[:element] +  results[element] + display_key[element+crib_len:] 
				elif(message_or_key == 'k'):
					for element in list(seenpositions):
						element = int(element)
						display_key = display_key[:element] + crib + display_key[element+crib_len:]
						display_ctext = display_ctext[:element] +  results[element] + display_ctext[element+crib_len:]
		elif str(response) == 'rep':
			message_or_key = ''
			while (message_or_key != 'm' and message_or_key != 'k'):
				message_or_key = raw_input("Is this crib part of the message or key? Please enter 'm' or 'k': ")
				if(message_or_key == 'm'):
					for element in list(seenrepeatedpositions):
						element = int(element)
						display_ctext = display_ctext[:element] + crib + display_ctext[element+crib_len:]
						display_key = display_key[:element] +  results[element] + display_key[element+crib_len:] 
				elif(message_or_key == 'k'):
					for element in list(seenrepeatedpositions):
						element = int(element)
						display_key = display_key[:element] + crib + display_key[element+crib_len:]
						display_ctext = display_ctext[:element] +  results[element] + display_ctext[element+crib_len:]
		else:		
			response = int(response)
			message_or_key = ''
			while (message_or_key != 'm' and message_or_key != 'k'):
				message_or_key = raw_input("Is this crib part of the message or key? Please enter 'm' or 'k': ")
				if(message_or_key == 'm'):
					display_ctext = display_ctext[:response] + crib + display_ctext[response+crib_len:]
					display_key = display_key[:response] + results[response] + display_key[response+crib_len:]
				elif(message_or_key == 'k'):
					display_key = display_key[:response] + crib + display_key[response+crib_len:]
					display_ctext = display_ctext[:response] + results[response] + display_ctext[response+crib_len:]
				else:	
					print 'Invalid response. Try again.'

	except ValueError:
		if response == 'end':
			print "Your message is: " + display_ctext
			print "Your key is: " + display_key
		elif response == 'none':
			print "No changes made."
		else:
			print "Invalid entry."
