    unsigned int nonFloatingWindows = 0;

    using lbPair = std::pair<const long unsigned int, 
                             std::unique_ptr<IWindow>>;

    // couting only non-floating windows to calcule the areas
    // for tiling them.
    std::for_each(
            _desktops[_currentDesktop].begin(),
            _desktops[_currentDesktop].end(),

            // lambda - use nonFloatingWindows variable as
            // reference, it will be incresead if the window is
            // not floating
            [&nonFloatingWindows](lbPair& wnd)
                { 
                    if (!wnd.second->floating())
                        ++nonFloatingWindows;
                }
            );