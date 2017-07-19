def factory():
    values = []
    def widget(value):
        values.append(value)
        return values
    return widget

worker = factory()
worker(1)
worker(2)
print worker(4)