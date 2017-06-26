    def listen1(self):

        self._console.eventAddCallback(libvirt.VIR_STREAM_EVENT_READABLE,
                                       self._send_to_client,
                                       None)

        def libvirt_event_loop():
            while True:
                libvirt.virEventRunDefaultImpl()

        libvirt_loop = threading.Thread(target=libvirt_event_loop)
        libvirt_loop.daemon = True
        libvirt_loop.start()

        inputs = [self._socket]

        while True:
            read_socket, _, _  = select.select(inputs, [], [], 0.1)

            for socket in read_socket:
                if socket is self._socket:
                    client, client_addr = socket.accept()
                    if self._current_fd is not None and \
                       self._current_fd is not client:
                        print 'error...'
                        return

                    inputs.append(client)
                    client.setblocking(0)
                    self._current_fd = client

                elif socket is self._current_fd:
                    data = socket.recv(1024)
                    if not data:
                        break
                    self._console.send(data)