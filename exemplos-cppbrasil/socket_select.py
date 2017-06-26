import select
import socket
import os

serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
serv.bind(('', 9090))
serv.listen(1)

sockets = [serv]

while True:

    # mantem todos os sockets abertos em escuta
    read_input, _, _ = select.select(sockets, [], [])

    # para cada um dos sockets prontos para leitura
    for socket in read_input:

        # aceita uma nova conexao caso o socket para leitura
        # seja o servidor
        if socket == serv:
            sockets.append(socket.accept()[0])

        # imprime os dados caso o socket para leitura seja
        # o cliente
        else:
            d = socket.recv(1024)[:-2]

            if d == 'q':
                socket.close()
                sockets.remove(socket)
            else:
                print d

    # encerra caso nao tenha mais cliente conectados
    if len(sockets) == 1:
        break
        
serv.close()