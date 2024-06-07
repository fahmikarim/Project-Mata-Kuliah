function varargout = KNN(varargin)
% KNN MATLAB code for KNN.fig
%      KNN, by itself, creates a new KNN or raises the existing
%      singleton*.
%
%      H = KNN returns the handle to a new KNN or the handle to
%      the existing singleton*.
%
%      KNN('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in KNN.M with the given input arguments.
%
%      KNN('Property','Value',...) creates a new KNN or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before KNN_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to KNN_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help KNN

% Last Modified by GUIDE v2.5 29-May-2024 10:39:37

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @KNN_OpeningFcn, ...
                   'gui_OutputFcn',  @KNN_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before KNN is made visible.
function KNN_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to KNN (see VARARGIN)

% Choose default command line output for KNN
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes KNN wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = KNN_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in showBtn.
function showBtn_Callback(hObject, eventdata, handles)
% hObject    handle to showBtn (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Mendeteksi opsi impor dari file CSV 'sephora_website_dataset.csv'
opts = detectImportOptions('sephora_website_dataset.csv');

% Memilih kolom 2 sampai 4 untuk diimpor
opts.SelectedVariableNames = (2:4);

% Membaca kolom yang dipilih dari file CSV dan mengonversinya menjadi sel array
label = table2cell(readtable('sephora_website_dataset.csv', opts));

% Memilih kolom 6 sampai 14 untuk diimpor
opts.SelectedVariableNames = (6:14);

% Membaca kolom yang dipilih dari file CSV dan mengonversinya menjadi sel array
attribute = table2cell(readtable('sephora_website_dataset.csv', opts));

% Menggabungkan data dari label dan attribute menjadi satu array sel
allData = [label attribute];

% Mengatur properti 'data' dari tabel GUI dengan data yang digabungkan
set(handles.tableData, 'data', allData);


% --- Executes on button press in classifyBtn.
function classifyBtn_Callback(hObject, eventdata, handles)

% Mengambil nilai input dari GUI
rating = str2double(get(handles.rating, 'string'));
NoR = str2double(get(handles.NoR, 'string'));
love = str2double(get(handles.love, 'string'));
price = str2double(get(handles.price, 'string'));
valuePrice = str2double(get(handles.valuePrice, 'string'));
k = str2double(get(handles.kV, 'string'));

%checking value
if isnan(rating) || isnan(NoR) || isnan(love) || isnan(price) || isnan(valuePrice) || isnan(k)
    errordlg('Mohon masukkan bobot yang valid', 'Input Error');
    return;
end
%checking value rating (0-5)
if rating < 0 || rating > 5
    errordlg('Mohon masukkan rating range 0 hingga 5', 'Input Error');
    return;
end

%ambil value dari radion button (true or false)
MF1 = get(handles.MF1,'value');
OO1 = get(handles.OO1,'value');
E1 = get(handles.E1,'value');
LE1 = get(handles.LE1,'value');

%pemberian value dari radion button (true or false)
if MF1
    MF = 1;
else 
    MF = 0;
end
    
if OO1
    OO = 1;
else 
    OO = 0;
end

if E1
    E = 1;
else 
    E = 0;
end

if LE1
    LE = 1;
else 
    LE = 0;
end

%proses KNN
sample = [rating NoR love price valuePrice MF OO E LE];

% Mengambil data pelatihan dari file CSV
opts = detectImportOptions('sephora_website_dataset.csv');
opts.SelectedVariableNames = (6:14);% Kolom atribut
training = readmatrix('sephora_website_dataset.csv', opts);

% Mengambil label dari file CSV
opts.SelectedVariableNames = (4);% Kolom label Category
label = readmatrix('sephora_website_dataset.csv', opts);

%model
model = fitcknn(training, label, 'NumNeighbors', k);
result = predict(model, sample);
disp(result)

opts = detectImportOptions('sephora_website_dataset.csv');
dataLabel = readtable('sephora_website_dataset.csv', opts);

% Menemukan baris di dataLabel yang sesuai dengan hasil model
matchingRow = dataLabel(strcmp(dataLabel.name, result), :); 

% Mengambil informasi tambahan berdasarkan hasil prediksi
resultBrand = matchingRow.brand; 
resultCategory = matchingRow.category; 

%tampilkan hasil GUI
set(handles.resultName, 'string', result);
set(handles.resultBrand, 'string', resultBrand);
set(handles.resultCategory, 'string', resultCategory);

function resultName_Callback(hObject, eventdata, handles)
% hObject    handle to resultName (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of resultName as text
%        str2double(get(hObject,'String')) returns contents of resultName as a double


% --- Executes during object creation, after setting all properties.
function resultName_CreateFcn(hObject, eventdata, handles)
% hObject    handle to resultName (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in MFTrue.
function MFTrue_Callback(hObject, eventdata, handles)
% hObject    handle to MFTrue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of MFTrue


% --- Executes on button press in MFFalse.
function MFFalse_Callback(hObject, eventdata, handles)
% hObject    handle to MFFalse (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of MFFalse


% --- Executes on button press in checkbox2.
function checkbox2_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox2


% --- Executes on button press in checkbox3.
function checkbox3_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox3



function rating_Callback(hObject, eventdata, handles)
% hObject    handle to rating (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of rating as text
%        str2double(get(hObject,'String')) returns contents of rating as a double


% --- Executes during object creation, after setting all properties.
function rating_CreateFcn(hObject, eventdata, handles)
% hObject    handle to rating (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function NoR_Callback(hObject, eventdata, handles)
% hObject    handle to NoR (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of NoR as text
%        str2double(get(hObject,'String')) returns contents of NoR as a double


% --- Executes during object creation, after setting all properties.
function NoR_CreateFcn(hObject, eventdata, handles)
% hObject    handle to NoR (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function love_Callback(hObject, eventdata, handles)
% hObject    handle to love (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of love as text
%        str2double(get(hObject,'String')) returns contents of love as a double


% --- Executes during object creation, after setting all properties.
function love_CreateFcn(hObject, eventdata, handles)
% hObject    handle to love (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function price_Callback(hObject, eventdata, handles)
% hObject    handle to price (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of price as text
%        str2double(get(hObject,'String')) returns contents of price as a double


% --- Executes during object creation, after setting all properties.
function price_CreateFcn(hObject, eventdata, handles)
% hObject    handle to price (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function valuePrice_Callback(hObject, eventdata, handles)
% hObject    handle to valuePrice (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of valuePrice as text
%        str2double(get(hObject,'String')) returns contents of valuePrice as a double


% --- Executes during object creation, after setting all properties.
function valuePrice_CreateFcn(hObject, eventdata, handles)
% hObject    handle to valuePrice (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function kV_Callback(hObject, eventdata, handles)
% hObject    handle to kV (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of kV as text
%        str2double(get(hObject,'String')) returns contents of kV as a double


% --- Executes during object creation, after setting all properties.
function kV_CreateFcn(hObject, eventdata, handles)
% hObject    handle to kV (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function resultCategory_Callback(hObject, eventdata, handles)
% hObject    handle to resultCategory (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of resultCategory as text
%        str2double(get(hObject,'String')) returns contents of resultCategory as a double


% --- Executes during object creation, after setting all properties.
function resultCategory_CreateFcn(hObject, eventdata, handles)
% hObject    handle to resultCategory (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function resultBrand_Callback(hObject, eventdata, handles)
% hObject    handle to resultBrand (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of resultBrand as text
%        str2double(get(hObject,'String')) returns contents of resultBrand as a double


% --- Executes during object creation, after setting all properties.
function resultBrand_CreateFcn(hObject, eventdata, handles)
% hObject    handle to resultBrand (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in reset.
function reset_Callback(hObject, eventdata, handles)
% hObject    handle to reset (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.rating,'string','');
set(handles.NoR,'string','');
set(handles.love,'string','');
set(handles.price,'string','');
set(handles.valuePrice,'string','');
set(handles.kV,'string','');
