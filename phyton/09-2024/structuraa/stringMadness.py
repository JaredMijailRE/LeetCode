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
    for n in range(size):
        word = input()
        words.add(word)

    for n in range(size-1):
        n = input()
        n = n.split()
        for i in range(2):
            n[i] = int(n[i])
        last = n[0]
        words.data[n[0]-1] = words.data[n[0]-1] + words.data[n[1]-1]
    print(words.data[last - 1])
