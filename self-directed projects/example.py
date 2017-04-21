#These lines grab libraries of functions that we will use for this program.
import csv
import json

# This is a comment it has no effect on the code. I rarely use these in my
# own code, and I would bet dollars to donuts that your developer doesn't
# use these, but they're good to keep track of your thought process for
# later on
data = {}

# This is your list of field names in your spreadsheet.
fieldnames = ("shopify_customer_id", "first_name", "last_name",
              "stripe_customer_token", "paypal_customer_token", "email",
              "billing_address1", "billing_address2", "billing_zip",
              "billing_city", "billing_country", "billing_phone")

# your spreadsheet file saved as a comma-delimited .csv file
csvfile = open('file.csv', 'r')

# This is the data form that recharge uses to store/send updates to their
# server. You're going to end up doing a POST request with the data in this
# file. https://en.wikipedia.org/wiki/POST_(HTTP) <- for more info
jsonfile = open('file.json', 'w')

# Reads all of the csv file, and notes that the delimiter is a ','. If you
# find there are a lot of commas in your data, you can change the delimiter.
# both here, and in your spreadsheet when you download it."|" is also a good
# delimiter
reader = csv.DictReader(csvfile, delimiter=',')

# this code takes the list of fieldnames, and zips it up with each of the
# values in your csv file, in this example the shopify_id will go with the,
# first value, "first_name" will go with the second value, etc.
# It's worth noting, that empty cells will not be ignored (I don't think),
# by the computer.
for row in reader:
  json.dump(row,jsonfile)
  jsonfile.write('\n') # this adds a new line character after each customer

