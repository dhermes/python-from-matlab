DEBUG = True


def waldo(J):
    if DEBUG:
        print '=' * 60
        print 'type(J): %r' % (type(J),)
        print 'J.dtype: %r' % (J.dtype,)
        print 'J.shape: %r' % (J.shape,)
        print 'J:'
        print J
        print 'J.flags:'
        print J.flags
        print '=' * 60
    J *= 2.1
