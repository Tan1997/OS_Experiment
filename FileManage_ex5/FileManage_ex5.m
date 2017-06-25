% /**
%  * 
%  * @author:        胡文博
%  * @email:        huwenbo@mail.dlut.edu.cn
%  * @dateTime:        2017-06-11 22:57:22
%  * @description:     
%  */
len = rand(50,1)*8 + 2;%生成50个随机长度作为文件长度
map = zeros(25,20);%位示图矩阵
storagedFiles = [];
% 将随机生成的50个文件存储起来
for index = 1:size(len,1)
    [map,files] = saveFile(map,[num2str(index),'.txt'],len(index) );
    storagedFiles = [storagedFiles,files];
end
figure(1);%可视化当前位示图
imagesc(map);
title('Storaged 1.txt ~ 50.txt ');
% 删除奇数.txt
for i = 1:size(storagedFiles,2)/2
    map = deleteFile(map,storagedFiles(1,i));
    storagedFiles(i) = [];
end
figure(2);%可视化当前位示图
imagesc(map);
title('Deleted 1.txt, 3.txt, ... 49.txt ');
%创建题目（3）中的文件并存储起来
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
figure(3);%可视化当前位示图
imagesc(map),colorbar;
for i = 1:size(storagedFiles,2)
    disp(['name: ',storagedFiles(1,i).name,',    start block: ',num2str(storagedFiles(1,i).start),...
        ',    length: ',num2str(storagedFiles(1,i).len),'k']);
end
title('Storaged A.txt, B.txt, ... E.txt');