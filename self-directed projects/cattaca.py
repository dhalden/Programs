#! /usr/bin/python
import sys
def get_beg_sequences(seq_len, line, i):
      curr_beg = 15
      for j in range(5):
        beg = line[i:i+curr_beg].upper()
        # (#As + #Ts)*2 + (#Gs + #Cs)*4 >= 60
        # NumAs = beg.count('A')
        # NumTs = beg.count('T')
        # NumGs = beg.count('G')
        # NumCs = beg.count('C')
        temp = (beg.count('A') + beg.count('T'))*2 + (beg.count('G') + beg.count('C'))*4
        if((temp >= 56 and temp <= 67)):
            return beg
        else:
          curr_beg += 3
      return None

def get_end_sequences(seq_len, line, i):
      curr_end = 15
      for j in range(5):
        end = line[i+seq_len*3 - curr_end:i+seq_len*3].upper()
        # (#As + #Ts)*2 + (#Gs + #Cs)*4 >= 60
        # NumAs = end.count('A')
        # NumTs = end.count('T')
        # NumGs = end.count('G')
        # NumCs = end.count('C')
        temp = (end.count('A') + end.count('T'))*2 + (end.count('G') + end.count('C'))*4
        if((temp >= 56 and temp <= 67)):
            return end
        else:
          curr_end += 3

      return None

def get_sequences(w, seq_len, bline, eline):
  for i in range(0, len(bline) - seq_len*3,3):
    beg = get_beg_sequences(seq_len, bline,i)
    end = get_beg_sequences(seq_len, eline,i)
    if(beg != None and end != None):
      w.write(beg)
      w.write(" ")
      w.write(end)
      print("beg:", beg)
      print("end:", end)

    else:
      w.write("None")
    w.write("\n")



if __name__ == "__main__":
  try:
    input_file = sys.argv[1]
  except IndexError:
    input_file = "gattaca.txt"

  try:
    output_file = sys.argv[2]
  except IndexError:
    output_file = "gattaca.log"

  try:
    seq_len = sys.argv[3]
    seq_len = int(seq_len)
  except IndexError:
    seq_len = 34

  f = open(input_file, 'r')
  w = open(output_file, 'w')
  while True:
    bline = f.readline()
    eline = f.readline()
    if not eline: break
    get_sequences(w,seq_len,bline,eline)
  f.close()
  w.close()

