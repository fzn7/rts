% for k,v in classes.iteritems():
interface ${v.fqn}
{
    % for method in v.publicMethods:
        %if method[3] == False:
    ${method[0]} ${method[1]}(${method[2]});
        %else:
    //${method[0]} ${method[1]}(${method[2]});
        %endif
    % endfor
};
% endfor
