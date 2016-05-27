%% SAV4MI framework - Surf Detector Callback
% Author : Luca Luke Costantino (lucaluke.altervista.org)
% Source : github.com/lucaluke88/sav4mi-framework
function surf_detection_Callback(hObject, eventdata, handles)
    try
        if iscell(handles.input_image)
            if is_rgb(handles.input_image{handles.input_image_cursor})
                errordlg('Works only on grayscale images!');
            else
                axes(handles.output_image_axes); 
                imshow(handles.input_image{handles.input_image_cursor},[]);
                hold on;
                points = detectSURFFeatures(handles.input_image{handles.input_image_cursor});
                [handles.features, handles.valid_points] = extractFeatures(handles.input_image{handles.input_image_cursor}, points);
                plot(handles.valid_points.selectStrongest(10),'showOrientation',true);
            end
        else
            
            if is_rgb(handles.input_image)
                errordlg('Works only on grayscale images!');
            else
                axes(handles.output_image_axes); 
                imshow(handles.input_image,[]);
                hold on;
                points = detectSURFFeatures(handles.input_image);
                [handles.features, handles.valid_points] = extractFeatures(handles.input_image, points);
                plot(handles.valid_points.selectStrongest(10),'showOrientation',true);
            end
        end
        
        
        
        % save gui data
        guidata(hObject, handles);
    catch error
        errordlg(getReport(error,'basic','hyperlinks','off'));
    end
end