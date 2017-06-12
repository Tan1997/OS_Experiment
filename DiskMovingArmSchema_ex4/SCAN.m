% /**
%  * 
%  * @author:        胡文博
%  * @email:        huwenbo@mail.dlut.edu.cn
%  * @dateTime:        2017-06-12 16:00:49
%  * @description:     
%  */
function [responseVec,movingArmNum] = SCAN(startPoint,accessSequence)
    Infinity = 10000000000000;

    responseVec = zeros(length(accessSequence)+1,1);
    responseVec(1) = startPoint;
    movingArmNum = 0;
    [~,index] = min(abs(accessSequence-startPoint) );
    if(accessSequence(index) >= startPoint)
        direction = 1;
    else
        direction = -1;
    end
    
    
    for i = 2:length(responseVec)
        if( (direction==1 && responseVec(i-1) > max(accessSequence)) ...
            || (direction == -1 && responseVec(i-1) < min(accessSequence))...
            )
            direction = 0-direction;
        end
        tmp = accessSequence-responseVec(i-1);
        if(direction == 1)
            tmp(tmp<=0) = Infinity;
        else
            tmp(tmp>=0) = -Infinity;
        end
        [step,index] = min(abs(tmp));
        movingArmNum = movingArmNum + step;
        responseVec(i) = accessSequence(index) ;
        accessSequence(index) = [];
    end
end