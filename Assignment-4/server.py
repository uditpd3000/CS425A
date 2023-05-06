from socket import *

serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(("localhost", serverPort))

print("The server is ready to receive")

while True:
    message, addr = serverSocket.recvfrom(1024)
    print("Connection from", addr, "is established")
    sentence = message.decode()
    capitalizedSentence = sentence.upper()

    serverSocket.sendto(capitalizedSentence.encode(),addr)
