class staticStack():
    def __init__(self, size: int):            
        self.data = [None]*size
        self.size = 0
    
    def pop(self):
        if(self.size == 0):
            print('Non element to delete')
        else: self.size -= 1
        
    def add(self, value: int):
        if(self.size == len(self.data)):
            print('list is full')
        else:
            self.data[self.size] = value
            self.size += 1
            
if __name__ == '__main__':
    size = int(input())
    last = 0
    words = staticStack(size)
    temp = []
    for n in range(size):
        word = input()
        words.add(word)
        answers = [n]
        temp.append(answers)

    for n in range(size-1):
        n = list(map(int, input().split()[:2]))
        last = n[0]-1
        for l in temp[n[1]-1]:
            temp[n[0]-1].append(l) 
        temp[n[1]-1] = ""
        
    for n in temp[last]:
        print(words.data[n], end='')
