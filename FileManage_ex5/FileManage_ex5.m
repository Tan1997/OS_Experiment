len = rand(50,1)*8 + 2 ;
map = zeros(25,20);

storagedFiles = [];

for index = 1:size(rawFiles.len,1)
    [map,files] = saveFile(map,[num2str(index),'.txt'],len(index) );
    storagedFiles = [storagedFiles,files];
end

figure(1);
imagesc(map);
for i = 1:size(storagedFiles,2)
    disp(['name: ',storagedFiles(1,i).name,',    start block: ',num2str(storagedFiles(1,i).start),...
        ',    length: ',num2str(storagedFiles(1,i).len),'k'])
end

for i = 1:size(storagedFiles,2)/2
    map = deleteFile(map,storagedFiles(1,i));
    storagedFiles(i) = []
end

figure(2);
imagesc(map);
for i = 1:size(storagedFiles,2)
    disp(['name: ',storagedFiles(1,i).name,',    start block: ',num2str(storagedFiles(1,i).start),...
        ',    length: ',num2str(storagedFiles(1,i).len),'k'])
end

[map,files] = saveFile(map,'A.txt',7 );
storagedFiles = [storagedFiles,files];
[map,files] = saveFile(map,'B.txt',5 );
storagedFiles = [storagedFiles,files];
[map,files] = saveFile(map,'C.txt',2 );
storagedFiles = [storagedFiles,files];
[map,files] = saveFile(map,'D.txt',9 );
storagedFiles = [storagedFiles,files];
[map,files] = saveFile(map,'E.txt',3.5 );
storagedFiles = [storagedFiles,files];

figure(3);
imagesc(map);
for i = 1:size(storagedFiles,2)
    disp(['name: ',storagedFiles(1,i).name,',    start block: ',num2str(storagedFiles(1,i).start),...
        ',    length: ',num2str(storagedFiles(1,i).len),'k'])
end