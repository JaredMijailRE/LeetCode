class SCA:
    def __init__(self, max_size):
        self.max_size = max_size
        self.size = 0
        self.data = [None] * max_size
        self.start = 0

    def is_empty(self):
        return self.size == 0
    
    def is_full(self):
        return not(abs(self.start + self.size) == self.max_size)

    def push_front(self, element):
        if self.is_full(): raise OverflowError("List is full")
        
        self.start -= 1
        self.data[self.start] = element
        self.size += 1

    def push_back(self, element):
        if self.is_full(): raise OverflowError("List is full")
        
        self.data[self.size] = element
        self.size += 1

    def pop_front(self):
        if self.is_full(): raise OverflowError("List is full")
    
        self.start += 1
        self.size -= 1

    def pop_back(self):
        if self.is_full(): raise OverflowError("List is full")
        
        self.size -= 1

    def find(self, element):
        for i in range(self.start, self.size):
            if self.data[i] == element:
                return True
        return False

    def erase(self, element):
        index = -1
        for i in range(self.start, self.size):
            if self.data[i] == element:
                index = i
                break
        if index == -1:
            raise ValueError("Element not found")
        for i in range(index, self.size - 1):
            self.data[i] = self.data[i + 1]
        self.size -= 1

    def add_before(self, target, element):
        index = -1
        for i in range(self.size):
            if self.data[i] == target:
                index = i
                break
        if index == -1:
            raise ValueError("Target not found")
        if self.size >= self.max_size:
            raise OverflowError("List is full")
        for i in range(self.size, index, -1):
            self.data[i] = self.data[i - 1]
        self.data[index] = element
        self.size += 1

    def add_after(self, target, element):
        index = -1
        for i in range(self.size):
            if self.data[i] == target:
                index = i
                break
        if index == -1:
            raise ValueError("Target not found")
        if self.size >= self.max_size:
            raise OverflowError("List is full")
        for i in range(self.size, index + 1, -1):
            self.data[i] = self.data[i - 1]
        self.data[index + 1] = element
        self.size += 1

    def printf(self): #1
        text = ""
        for index in range(self.start, self.size):
            n = self.array[index]
            if(index == 0):
                text = text + str(n)
            else:
                text = text + " " + str(n)
        text = '[' + text + ']'
        print('Elementos en el arreglo: ' + text)

    def selector(self, select: str):
        
        if select.startswith('1'):
            self.printf()
        elif select.startswith('2'):
            text = select.split()
            self.push_back(text[1])
        elif select.startswith('3'):
            self.pop_back()
        elif select.startswith('4'):
            text = select.split()
            self.push_front(text[1])
        elif select.startswith('5'):
            self.pop_front()
            

size = input()
Array = SCA(int(size))
while True:
    try:
        selections = input()
    except EOFError:
        break
    Array.selector(selections)
