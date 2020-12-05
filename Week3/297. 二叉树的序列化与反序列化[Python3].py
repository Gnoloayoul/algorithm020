class Codec:
    def serialize(self, v):
        return f'{v.val} left {self.serialize(v.left)} right {self.serialize(v.right)} u' if v else '-'

    def deserialize(self, data):
        tokens = iter(data.split())
        def f():
            t = next(tokens)
            if t == '-':
                return None
            res = TreeNode(int(t))
            t = next(tokens)
            for child in ('left', 'right'):
                if t == child:
                    setattr(res, child, f())
                    t = next(tokens)
            return res
        return f()