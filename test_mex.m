zap = [
    1.0, 2.0, 3.0;
    4.0, 5.0, 6.0
];
disp('zap before:');
disp(zap);
zap_new = foo_mex(zap);
disp('foo_mex(zap):');
disp(zap_new);
disp('zap after:');
disp(zap);
