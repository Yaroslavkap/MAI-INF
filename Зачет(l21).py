import os

path = str(input())

def obxodFile(path, level=1):
    
    
        
    for i in os.listdir(path):
        
        b = path + '/' + i
        if 'Makefile' in b:
            print(b.replace('/', '|'))
            
        if os.path.isdir(path + '/' + i):
           
            obxodFile(path + '/' + i, level + 1)
            
obxodFile(path)
