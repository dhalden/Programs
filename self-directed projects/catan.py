class Player():
  def __init__(self, name):
    self.rnames = ('w','s','l','b','o')
    self.name = name
    self.settlements = []
    self.curResources = {'w':0, 's':0, 'b':0, 'o':0, 'l':0}
    self.total = {'w':0, 's':0, 'b':0, 'o':0, 'l':0}

  def addSettlement(self, chitlist):
    st1 = [1]
    for j in range(3):
      settle = raw_input("Input 1 of the 3 letters surrounding the settlement ")
      if(chitlist[settle][1] == ''):
        resource = raw_input(
          "Resource? (wheat:w, sheep:s, lumber:l, brick:b, ore:o) ")
        while (resource not in self.rnames):
          resource = raw_input(
            "Resource? (wheat:w, sheep:s, lumber:l, brick:b, ore:o) ")
        chitlist[settle][1] = resource
      if (settle in chitlist):
        st1.append((settle, chitlist[settle][1]))
    self.settlements.append(st1)
    print(self.settlements)
    self.curResources['w'] -= 1
    self.curResources['s'] -= 1
    self.curResources['l'] -= 1
    self.curResources['b'] -= 1

  def updateResources(self, rollkeys):
    for i in self.settlements:
      for j in i[1:]:
        print(j)
        if (j[0] in rollkeys):
          self.curResources[j[1]] += i[0]
          self.total[j[1]] += i[0]

  def upradeToCity(self):
    self.curResources['w'] -= 2
    self.curResources['o'] -= 3
    settle = raw_input("What is the settlement number (zero indexed): ")
    self.settlements[settle][0] = 2

  def buildRoad(self):
    self.curResources['l'] -= 1
    self.curResources['b'] -= 1

  def develop(self):
    self.curResources['w'] -= 1
    self.curResources['o'] -= 1
    self.curResources['s'] -= 1

  def clearResources(self):
    self.curResources = {'w':0, 's':0, 'b':0, 'o':0, 'l':0}

def updateAllResources(rollkeys, players):
  for player in players:
    players[player].updateResources(rollkeys)

oplayer = {'a':5, 'b':2, 'c':6, 'd':3}
tt4player = {'a':5, 'b':2, 'c':6, 'd':3, 'e':8, 'f':10, 'g':9, 'h':12, 'i':11,
             'j':4, 'k':8, 'l':10, 'm':9, 'n':4, 'o':5, 'p':6, 'q':3, 'r':11}
ft6player = {'a':2, 'b':5, 'c':4, 'd':6, 'e':3, 'f':9, 'g':8, 'h':11, 'i':11,
            'j':10, 'k':6, 'm':8, 'n':4, 'o':8, 'p':10, 'q':11, 'r':12, 's':10,
            't':5, 'u':4, 'v':9, 'w':5, 'x':9, 'y':12, 'za':3, 'zb':2, 'zc':6}

numplayers = int(raw_input("How many players? "))
if(numplayers < 5 and numplayers > 2):
  chits = tt4player
elif(numplayers < 7 and numplayers > 4):
  chits = ft6player
else:
  chits = oplayer

rolldistributions = chits
rollkeys = {}
for a in chits:
  if (chits[a] not in rollkeys.keys()):
    rollkeys[chits[a]] = []
  rollkeys[chits[a]].append(a)
  rolldistributions[a] = [0, '']

print(rollkeys)
print(rolldistributions)
players = {}
for i in range(numplayers):
  p = raw_input("What is the name of Player %d? " % (i+1))
  players[p] = Player(p)
  players[p].addSettlement(rolldistributions)

for i in reversed(players.keys()):
  players[i].addSettlement(rolldistributions)
  players[i].clearResources()

rolls = {2:0, 3:0, 4:0, 5:0, 6:0, 7:0, 8:0, 9:0, 10:0, 11:0, 12:0}
robbertile = ''

action = raw_input("what is the roll? (k for knight): ")
while(action != 'q'):
  if(action == 'k' or action == '7'):
    robbertile = raw_input("Letter of new Robber Space? ")
    #move the robber
  elif(action.isdigit() and (int(action) > 1 and int(action) < 13)):
    action = int(action)
    rolls[action] += 1
    #ind = rollkeys[action].index(robbertile)
    #updateAllResources((rollkeys[action][:ind] + rollkeys[action][ind+1:]), players)
    for i in rollkeys[action]:
      if(robbertile != i):
        rolldistributions[i][0] += 1
  action = raw_input("what is the roll? (k for knight): ")


print(rolls)
print(rolldistributions)
for player in players:
  print(players[player].total)
  print(players[player].curResources)
