% for k,v in classes.iteritems():
    % if v.ignoreFlagPresent() is True:
        % for comment in v.comments:
//${comment}
        % endfor
/*interface ${v.name.label}
    % else:
        % for comment in v.comments:
//${comment}
        % endfor
interface ${v.name.label}
    % endif
{
    % for method in v.publicMethods:
        % if method:
            % for comment in method.comments:
	//${comment}
            % endfor
	//${method.name.label}



        % endif
    % endfor
    % if v.ignoreFlagPresent() is True:
};*/
    % else:
};
    % endif
% endfor
