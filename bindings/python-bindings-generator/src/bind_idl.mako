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
    % if v.defaultConstructor:
    //Constructor
    void ${v.defaultConstructor.name.label}();
    % endif

    % for method in v.publicMethods:
        % if method:
            % for comment in method.comments:
	//${comment}
            % endfor
			<% method_args = "" %>
            % if method.arguments:
                <% method_args = ", ".join(list(map(lambda argument: "{} {}".format(argument.type.kind.label, argument.label.label), method.arguments))) %>
			% endif
			% if method.ignoreFlagPresent() is True:
	//${method.returnType.kind.label} ${method.name.label}(${method_args});
			% else:
	//${method.returnType.kind.label} ${method.name.label}(${method_args});
			% endif
        % endif
    % endfor
    % if v.ignoreFlagPresent() is True:
};*/
    % else:
};
    % endif
% endfor
