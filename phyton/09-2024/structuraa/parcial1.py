class Node:
    def __init__(self, data: int):
        self.data = data
        self.next = None
        self.prev = None
        

class DoublyLinked:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def push_back(self, data):
        new_node = Node(data)
        if not self.tail: 
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
        self.size += 1

    def push_front(self, data: int):
        new_node = Node(data)
        if not self.head: 
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.size += 1

    def pop_front(self):
        if not self.head:
            raise IndexError("La cola esta vacia")
        data = self.head.data
        self.head = self.head.next
        if self.head:
            self.head.prev = None
        else:
            self.tail = None 
        self.size -= 1
        return data

    def pop_back(self):
        if not self.tail:
            raise IndexError("La cola esta vacia")
        data = self.tail.data
        self.tail = self.tail.prev
        if self.tail:
            self.tail.next = None
        else:
            self.head = None  
        self.size -= 1
        return data

    def front(self):
        if not self.head:
            raise IndexError("La cola esta vacia")
        return self.head.data

    def back(self):
        if not self.tail:
            raise IndexError("La cola esta vacia")
        return self.tail.data

    def __len__(self):
        return self.size

    def __str__(self):
        elements = []
        current = self.tail
        while current:
            elements.append(current.data)
            current = current.prev
            try:
                if(current.data == 0 and (current.prev.data == 0 )):
                    break
            except:
                pass
        return  " ".join(map(str, elements))
    
def get_data(operador: Node)-> int:
    if operador == None:
        return 0
    else:
        return operador.data

def go_next(operador: Node)-> Node:
    if operador == None:
        return None
    else:
        return operador.next

def reversed(operador: list)-> DoublyLinked:
    newOperdor = DoublyLinked()
    for n in range(len(operador)):
        index = len(operador) - n -1
        if operador[index] == ' ':
            pass
        else:
            newOperdor.push_front(int(operador[index]))
    return newOperdor

def sum_list(operador1: DoublyLinked, operador2: DoublyLinked):
    temp1 = operador1.head
    temp2 = operador2.head
    answer = DoublyLinked()
    residuo = 0
    while (temp1 != None or temp2 != None or residuo != 0):
        result = get_data(temp1) + get_data(temp2) + residuo
        answer.push_front(result%10)
        residuo = result//10
        temp1 = go_next(temp1)
        temp2 = go_next(temp2)
    return answer
        


def solution(operador1: list, operador2: list):
    operador1 = reversed(operador1)
    operador2 = reversed(operador2)
    answer = sum_list(operador1, operador2)
    print(str(answer))

if __name__ == '__main__':
    operador1 = input()
    operador2 = input()
    solution(operador1, operador2)

