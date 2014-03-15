import subprocess
proc = subprocess.Popen(
            'python',stdout=subprocess.PIPE,
                stdin=subprocess.PIPE)
proc.stdin.write('import antigravity\n')
proc.stdin.write('print "something"\n')
proc.stdin.close()
result = proc.stdout.read()
print result
