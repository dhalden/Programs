#String Manipulation
#demonstrates string methods

#Quote from someone... I think it's Mark Twain
quote ="The editorial 'we' is reserved for kings, writers, and people with tapeworms"

print("original quote")
print(quote)

print("\nIn uppercase")
print(quote.upper())

print("\nIn lowercase")
print(quote.lower())

print("\nAs a title")
print(quote.title())

print("\nWith a minor replacement")
print(quote.replace("editorial","royal"))

print("\nOriginal quote is still")
print(quote)

print("\nStripped quote")
print(quote.strip())

quote = quote.title()

print("\nInverted quote text")
print(quote.swapcase())


opinion = input("\n\nDid you like the quote? ")
