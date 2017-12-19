% for k,v in classes.iteritems():
	% for comment in v.comments:
//${comment}
	% endfor
interface ${v.name.label}
{
    % for method in v.publicMethods:
        % if method:
            % for comment in method.comments:
	//${comment}
            % endfor
    //${method.name.label}



        % endif
    % endfor
};
% endfor
